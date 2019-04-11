// 4_도형편집기1 - 15 page
#include <iostream>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
	virtual void Draw() override { cout << "Rect Draw" << endl; }
};
class Circle : public Shape
{
public:
	virtual void Draw() override { cout << "Circle Draw" << endl; }
};
//--------------------------
// Command 패턴 모든 명령을 객체화 한다.
struct ICommand
{
	virtual void Execute() = 0;
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
};

// 사각형을 추가하는 명령
struct AddRectCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddRectCommand(vector<Shape*>& a) : v(a) {}
	virtual void Execute() { v.push_back(new Rect); }
	virtual bool CanUndo() { return true; }
	virtual void Undo()
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};
struct AddCircleCommand : public ICommand
{
	vector<Shape*>& v;
public:
	AddCircleCommand(vector<Shape*>& a) : v(a) {}
	virtual void Execute() { v.push_back(new Circle); }
	virtual bool CanUndo() { return true; }
	virtual void Undo()
	{
		Shape* p = v.back();
		v.pop_back();
		delete p;
	}
};
struct DrawCommand : public ICommand
{
	vector<Shape*>& v;
public:
	DrawCommand(vector<Shape*>& a) : v(a) {}
	virtual void Execute()
	{
		for (int i = 0; i < v.size(); i++)
			v[i]->Draw();
	}
	virtual bool CanUndo() { return true; }
	virtual void Undo() { system("cls"); }
};

class MacroCommand : public ICommand
{
	vector<ICommand*> v;
public:
	void AddCommand(ICommand* p) { v.push_back(p); }
	void Execute()
	{
		for (auto p : v)
			p->Execute();
	}
};

#include<stack>

int main()
{
	vector<Shape*> v;


	MacroCommand* mc = new MacroCommand;
	mc->AddCommand(new AddRectCommand(v));
	mc->AddCommand(new AddCircleCommand(v));
	mc->AddCommand(new DrawCommand(v));
	mc->Execute();

	MacroCommand* mc1 = new MacroCommand;
	mc->AddCommand(new AddRectCommand(v));
	mc->AddCommand(new AddCircleCommand(v));

	stack<ICommand*> cmd_stk; // 사용자의 모든 명령
	ICommand* p = 0;

	while (1)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			p = new AddRectCommand(v);
			p->Execute();
			cmd_stk.push(p);
		}
		else if (cmd == 2)
		{
			p = new AddCircleCommand(v);
			p->Execute();
			cmd_stk.push(p);
		}
		else if (cmd == 9)
		{
			p = new DrawCommand(v);
			p->Execute();
			cmd_stk.push(p);
		}
		else if (cmd == 0)
		{
			p = cmd_stk.top();
			cmd_stk.pop();

			if (p->CanUndo())
				p->Undo();

			delete p;
		}
	}
}




