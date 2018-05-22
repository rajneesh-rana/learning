#include<iostream>

using namespace std;
int R, C;
char P1[300][300];
char P2[300][300];


int ok(int r, int c,int ans){
	int flag=true;
	for(int j=1;j<r+ans;j++){
		for(int k=1;k<c+ans;k++){
			if(P2[j][k]=='#' || j>R || k>C){
				flag=false;
					return 0;

			}				
		}
	}

	for(int j=1;j<r+ans;j++){
		for(int k=1;k<c+ans;k++){
			P2[j][k]='X';
			}				
		}
	return true;
}
void color(int ans){
	for(int j=1;j<=R;j++)
		for(int k=1;k<=C;k++){
				if(P2[j][k]=='_' || P2[j][k]=='?' || P2[j][k]=='X'){
					if(!ok(j,k,ans))
						return;
				}
		}
}



int check(){
	int A=(R>C?C:R);
	
	while(A>1){
	for(int j=1;j<=R;j++)
		for(int k=1;k<=C;k++)
			P2[j][k]=P1[j][k];
		
		color(A);
	int flag=true;
	for(int j=1;j<=R;j++){
		for(int k=1;k<=C;k++){
			if(P2[j][k]=='_'){
				flag=false;
				break;
			}				
		}
		if(!flag)
			break;
	}
	
	if(flag)
		return A;
	else 
		A--;

	}
	return A;
}



int main(){
	int tc;
	cin>>tc;
	for(int i=1;i<=tc;i++){
		cin>>R>>C;
		for(int j=1;j<=R;j++)
			for(int k=1;k<=C;k++)
				cin>>P1[j][k];

		cout<<check()<<endl;
	}


}
