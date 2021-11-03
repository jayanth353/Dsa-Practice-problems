n=int(input())
l=[1]*(n+1)
for i in range(2,int(n**(1/2))+1):
    
    if(l[i]==1):
        for j in range(i**2,n+1,i):
            l[j]=0
for k in range(2,len(l)):
    if l[k]==1 :
        print(k,end=" ")
