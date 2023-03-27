import random as  rr
print('Till he has Two Boys, he will produce children, with manipulation')
n = 1000
Repeat = 1000
more_Girls = 0
Sum = 0
for i in range(Repeat):

    arr = [[] for _ in range(n)]

    for j in range(n):
        k = rr.randint(1,2)
        arr[j].append(k)
        while k != 2 and len(arr[j])<4:
            k = rr.randint(1,2)
            arr[j].append(k)
        k = rr.randint(1,2)
        arr[j].append(k)
        while k != 2 and len(arr[j])<4:
            k = rr.randint(1,2)
            arr[j].append(k)
        
        if 1 in arr[j] and j%50==0:
            arr[j].remove(1)
        
        # print(f'arr[{i}] = {arr[i]}')

    # Find count of all 1's and 2's in the arr
    count1 = 0
    count2 = 0
    for i in range(n):
        count1 += arr[i].count(1)
        count2 += arr[i].count(2)


    # print(f'Count of Girls: {count1}')
    # print(f'Count of Boys: {count2}')
    # print(f'Ratio of Girls to Boys: {count1/count2}')
    # Assume 1 as girl child and 2 as boy child
    # Tell the Gender Ratio

    # print(f'Gender Ratio: {(count2/count1*1000).__round__(2)}')
    Sum += count1/count2*1000
    if count1 > count2:
        more_Girls += 1
    #     Extra = count1 - count2
    #     print(f'The excess number of Girls are: {Extra}')
    # else:
    #     Extra = count2 - count1
    #     print(f'The excess number of Boys are: {Extra}')

print(f'Number of Time more Girls that Boys(%) = {more_Girls/Repeat*100:.2f}%')
print(f'Average Gender Ratio = {Sum/Repeat:.2f}')
