#https://codeforces.com/contest/1613/problem/C

def can_make_damage(m):
    t_damage=0
    for i in range(n-1):
        if(hit_sec[i+1]-hit_sec[i]>m):
            t_damage+=m
        else:
            t_damage+=hit_sec[i+1]-hit_sec[i]
    t_damage+=m
    if(t_damage<h):
        return False
    return True
        
t=int(input())
while t:
    
    n,h=map(int,input().split(' '))
    hit_sec=list(map(int,input().split(' ')))
    low,high=1,h
    ans=-1
    while low<=high:
        mid=(low+high)//2
        if(can_make_damage(mid)):
            ans=mid
            high=mid-1
        else:
            low=mid+1
    print(ans)
    t-=1
