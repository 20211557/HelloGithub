#include "kmp.h"

void printMenu(){
	cout<<"메뉴 선택"<<endl;
	cout<<"1. 댓글 입력 2. 댓글 찾기 3. 댓글 보기 4. 나가기"<<endl;
}

void printComments(string* box, int size){
	if(size>0){
		cout<<"***************************************"<<endl;
		for(int i = 1;i<=size;i++){
			cout<<"*  "<<i<<" : "<<box[i-1]<<endl;
		}
		cout<<"***************************************"<<endl;
	}
	else cout<<"댓글 없음."<<endl;
}

void findComments(KMP kmp, string* box, int size){
	string temp;
	int num = 1;
	cout<<"찾고자 하는 댓글의 내용을 입력하세요: ";
	cin>>temp;

	kmp.fail(temp);
	for(int i = 0; i<size;i++){
		int k = kmp.Find(box[i],temp);
		if(k){
			cout<<num<<". "<<box[i];
			num++;
		}
	}
	cout<<"총 "<<num-1<<"개의 댓글을 찾았습니다."<<endl;
}
	
int main(){
	KMP cont;
	int menuNum,currentSize=0;
	bool flag = false;
	string* comments = new string[100];
	string comment;

	while(!flag){
		printMenu();
		cin>>menuNum;
		switch(menuNum){
			case 1:
				if(currentSize>=100){
					cout<<" 더 이상 쓸 수 없습니다."<<endl;
					break;
				}
				cout<<"댓글 : ";
				cin>>comment;
				comments[currentSize++] = comment;
				cout<<"댓글 입력 완료"<<endl;
				break;
			case 2:
				findComments(cont,comments,currentSize);
				break;
			case 3:
				printComments(comments,currentSize);
				break;
			case 4:
				flag =true;
				cout<<"종료"<<endl;
				break;
			default:
				break;
		}
	}
}

