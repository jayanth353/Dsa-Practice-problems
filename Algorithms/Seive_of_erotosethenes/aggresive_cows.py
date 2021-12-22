def canPlace(d,l,cows):
    cnt=cows
    last=-1
    for i in l:
        if(i-last>=d or last==-1):
            cnt-=1
            last=i
        if cnt<0:break
    return cnt==0

cows=3   
l=[1,2,8,4,9]
l.sort()
low=int(0)
high=int(1e5)

while high-low>1:
    
    mid=(low+high)//2
    if(canPlace(mid,l,cows)):
        low=mid
    else:high=mid-1
if(canPlace(high,l,cows)):
    print(high)
else:print(low)
