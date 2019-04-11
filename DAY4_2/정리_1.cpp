/*
정리 1
핵심 1. 공통성과 가변성의 분리
     2. A와 B를 묶어야 한다면 - 공통의 기반 클래스
	 3. 간접층을 통해서 인터페이스 변경, 유연성, 쉬운 사용 등을 추구

GoF 패턴의 분류
1. 생성 5개: singleton, abstract factory, factory method, prototype, builder
2. 구조(structure) 7개: adapter, proxy, bridge, facade, composite, decorator, flyweight
3. 행위(behavior) 11개: template method, strategy, iterator, visitor, observer, state

변하는 것과 변하지 않는 것을 분리하는 기술
1. 변하는 것을 가상함수로
    A. template method: 변하는 것이 알고리즘 또는 어떤 정책
	B. factory method: 변하는 가상함수가 하는 일은 결국 객체 생성
2. 변하는 것을 다른 클래스로
    A. strategy: 알고리즘을 교체하기 위한 것 
	B. state: 객체의 상태에 따른 동작의 변경
	C. builder: 복잡한 형태의 객체를 만들 때 만드는 과정은 동일(모자, 유니폼, 신발)
	            하지만 각 단계의 표현이 다를 때 (축구 게임 국가별 유니폼)
	            결국, 객체를 만들 때 사용하는 패턴
*/