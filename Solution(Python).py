text = input("Enter the text:")
left = int(input("Enter the left width:"))
right = int(input("Enter the right width:"))
width = int(input("Enter the width:"))

list1= text.split()        #Split based on space
z = " ".join(list1);       #Join them on single space. Multiple spaces removed.
print("After removing multiple spaces(if any): \n",z)

for i,ele in enumerate(z):
    if(i!=len(z)):
        if (z[i] in ('.','!',',')) and z[i+1]==' ':
            z = z[:i+2]+z[i+2].capitalize()+z[i+3:]
        elif (z[i] in ('.','!',',')) and z[i+1]!=' ':
            z = z[:i+1]+z[i+1].capitalize()+z[i+2:]
            z=z[:i+1]+' '+z[i+1:]

print("After capitalizing: \n",z)

count = 0
j=0
k=(width-(left+right))
offset=(width-(left+right))

print("Final result =")
while(j<=len(z)):
    for _ in range(width):
        if(j<=len(z)):
            for _ in range(left):
                print('#',end='')
            print(z[j:k],end='')
            j+=offset
            k+=offset
            for _ in range(right):
                print('*',end='')
            print()
        else:
            exit(0)