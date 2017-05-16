#pragma once

struct CksPoint2D {
	int x;
	int y;
	CksPoint2D ( int xx=0, int yy=0 ) { x = xx; y = yy; }
	bool operator==( CksPoint2D &p){//������ �����ε�
		return (p.x == x && p.y ==y);
	}
	
	bool isNeighbor(CksPoint2D &p){
		int dx = (x > p.x) ? (x - p.x) : (p.x - x); // x�� ���� �� ��� ���� 
		int dy = (y > p.y) ? (y - p.y) : (p.y - y); // y�� ���� �� ��� ���� 
		return ((dx+dy) == 1); //���� ������ ��ĭ ���� ������
		}
		
	
};