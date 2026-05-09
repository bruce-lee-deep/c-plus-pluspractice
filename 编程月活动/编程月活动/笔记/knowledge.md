# 2026.5.3
## 1.数学家丁丁妹
### 矩阵快速幂优化
矩阵快速幂（Matrix Fast Exponentiation）是处理线性递推关系的利器。它的核心思想是将原本需要 $O(n)$ 时间复杂度的递推计算，通过矩阵乘法的结合律和快速幂算法，优化到 $O(\log n)$
线性递推或者说动态规划可以用一个简单的矩阵乘法表示，找出矩阵只需求矩阵的n次幂
例如斐波那契数列
下面是矩阵快速幂的c++算法实现:
```cpp
struct Matrix{
    long long mat[MAXN][MAXN];
    Matrix(){memset(mat,0,sizeof(mat));}//初始化为领矩阵
};

//矩阵乘法
Matrix multiply(Matrix A,Matrix B,int n,int mod){
    Matrix c;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                c.mat[i][j]=c.mat[i][j]+A.mat[i,k]*B.mat[k,j]%mod;
            }
        }
    }
    return c;
}

//矩阵幂
Matrix power(Matrix A,long long p,int n,int mod){
    Matrix res;
    for(int i=0;i<n;i++) res.mat[i][i]=1;
    while(p>0){
        if(p&1)res=multiply(res,A,n,mod);//如果当前位为1，将结果乘上当前矩阵
        A=multiply(A,A,n,mod);//A不断地平方
        p>>=1;//右移一位
    }
    return res;
}
```
# 2026.5.9
## 下山（动态规划+dfs）
用vector时要注意越界，最简单的方法就是确保dp[i][j]里面的i和j都要小于dp预定的大小
### 处理地图上下左右四个方向的一般方法
```cpp
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
for(int i=0;i<4;i++){
    nx=x+dx[i];
    ny=y+dy[i];
}
```
