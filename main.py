x=input("enter integer: ")
x=int(x)
maxx=-999999
minn=999999
while(x!="done"):
    x=input("enter integer: ")
    if(x.lower()=="done"):
        break
    try:
        x=int(x)
        maxx=max(maxx,x)
        minn=min(minn,x)
    except Exception:
        print("INVALID INPUT")

print("Maximum number is:"+ str(maxx))
print("Minimum number is:"+ str(minn))