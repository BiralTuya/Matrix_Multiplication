#include<bits/stdc++.h>

using namespace std;

class Matrix{
    public:
    int m=0;
    int n=0;
    vector<vector<double> > mat;

    void getInput(){
        mat.clear();
        printf("Enter number of row and column:\n");
        scanf("%d %d",&m,&n);
        printf("Enter matrix elements:\n");
        for(int i=0;i<m;i++){
            mat.push_back(vector<double> ());
            for(int j=0;j<n;j++){
            mat[i].push_back(0);
            scanf("%lf",&mat[i][j]);
            }
        }
    }
    void showMatrix(){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
            printf("%lf ",mat[i][j]);
            }
            printf("\n");
        }
    }
    Matrix multiply(Matrix A){
        Matrix mul;
        if(A.m!=this->n) printf("This type of matrix cannot be multiplied\n");
        else{
            mul.m = this->m;
            mul.n = this->n;
            for(int i=0;i<this->m;i++){
                mul.mat.push_back(vector<double>());
                for(int k=0;k<A.n;k++){
                    mul.mat[i].push_back(0);
                    for(int j=0;j<this->n;j++){
                        mul.mat[i][k]+=this->mat[i][j]*A.mat[j][k];
                    }
                }
            }
        }
        return mul;
    }
    Matrix split(){
        Matrix m1,m2,m3,m4,res;
        if (this->m!=this->n){
            printf("Split can be performed with nxn matrix!\n");
            return res;
        }
        if (this->n<=2){
            printf("Matrix less than 2x2 cannot be splited\n");
            return *this;
        }
        int len=(this->n)/2;
        m1.m = m1.n = len;
        for(int i=0;i<len;i++){
            m1.mat.push_back(vector<double>(len));
            for(int j=0;j<len;j++){
                m1.mat[i][j]= this->mat[i][j];
            }
        }
        m2.m = m2.n = len;
        for(int i=len;i<this->n;i++){
            m2.mat.push_back(vector<double>(len));
            for(int j=0;j<len;j++){
                m2.mat[i - len][j]= this->mat[i][j];
            }
        }
        m3.m = m3.n = len;
        for(int i=0;i<len;i++){
            m3.mat.push_back(vector<double>(this->n));
            for(int j=len;j<this->n;j++){
                m3.mat[i][j - len]= this->mat[i][j];
            }
        }
        m4.m = m4.n = len;
        for(int i=len;i<this->n;i++){
            m4.mat.push_back(vector<double>(this->n));
            for(int j=len;j<this->n;j++){
                m4.mat[i - len][j - len]= this->mat[i][j];
            }
        }
        res=m1.multiply(m2).multiply(m3).multiply(m4);
        //res.showMatrix();
        return res.split();
    }

};

int main(){
    Matrix obj1,obj2,result,result2;

    obj1.getInput();
    printf("First Matrix is: \n");
    obj1.showMatrix();

    obj2.getInput();
    printf("Second Matrix is: \n");
    obj2.showMatrix();

    result= obj1.multiply(obj2);
    result.showMatrix();

    result2=obj1.split();
    result2.showMatrix();


}
