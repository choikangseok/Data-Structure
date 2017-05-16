#pragma once

struct CksPoint2D {
	int x;
	int y;
	CksPoint2D ( int xx=0, int yy=0 ) { x = xx; y = yy; }
	bool operator==( CksPoint2D &p){//연산자 오버로딩
		return (p.x == x && p.y ==y);
	}
	
	bool isNeighbor(CksPoint2D &p){
		int dx = (x > p.x) ? (x - p.x) : (p.x - x); // x의 뺄셈 값 양수 저장 
		int dy = (y > p.y) ? (y - p.y) : (p.y - y); // y의 뺄셈 값 양수 저장 
		return ((dx+dy) == 1); //원래 값에서 한칸 차이 나는지
		}
		
	
};