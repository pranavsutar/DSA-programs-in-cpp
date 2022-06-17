from cgitb import reset
from tkinter import *
import copy

from setuptools import Command
win = Tk()
win.title("Tic Tac Toe")
# win.iconbitmap('paintbox.ico')
win.config(bg= '#333')
win.minsize(width=240,height= 275)# w - 240, h- 211
win.maxsize(width=240,height= 1000)
# win.maxsize(width=1800, height=1000)
t0 = Label(win,text = '',bg = '#333' )

# t2 = Label(win,text = 'Draw!' )
Nh =3
Nv =3
startx = 0
starty = 0
t0.place(x = startx + 95, y = starty + 70*4-30)
global alternate
alternate = 1
# ll1 = [Label(win, text = "T" + str(i), bg= "blue", fg= 'white', width = 10, height= 1) for i in range(6)]
# ll2 = [Label(win, text = "U" + str(i), bg= "black", fg= 'white', width = 10, height= 1) for i in range(6)]
# for i in range(6):
#     ll1[i].place(x = 10, y = 100+25*i)
#     ll2[i].place(x = 90, y = 100+25*i)

def transform(ind,b,s):
    global a,lll,alternate,win,t0
    x = ind//3;y = ind%3;
    if(a[x][y] == 'O' or a[x][y] == 'X'):
        return
    a[x][y]=s
    show(a)
    if(check(a)):
        t0.config(bg = '#eee',fg = '#000', text = 'WON!!!')
        
        if whoWon(a) == 'X':
            print('Winner is Player 1 !!!\nCongratulations!!!')
        else:
            print('Winner is Player 2 !!!\nCongratulations!!!')
        for ii in range(3):
            for jj in range(3):
                lll[ii][jj].config(text = 'Won')
        
    if(draw(a)):
        t0.config(bg = '#eee',fg = '#000', text = 'DRAW!!!')
        print('The match is a Draw. Play Again.')
        for ii in range(3):
            for jj in range(3):
                lll[ii][jj].config(text = 'Draw')
    b.config(text = s)
    alternate = 1 - alternate
def invert():    
    global alternate
    
    if alternate :
        return 'X'
    return 'O'
# def lamTran(x,y):
#     return lambda lll,s : (lll[y][x].config(text = s))

# fll = [[lamTran(i,j) for  j in range(3)]for i in range(3)]

# lll = [[Button(win, text = str(3*item+j+1), bg= "black", fg= '#ffffff', width = 10, height = 2,command= lambda:fll[item][j](lll, 'X')) for item in range(Nv) ] for j in range(Nh)]
b0 = Button(win, text = str(0+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(0,b0, invert())) 
b1 = Button(win, text = str(1+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(1,b1, invert())) 
b2 = Button(win, text = str(2+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(2,b2, invert())) 

b3 = Button(win, text = str(3+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(3,b3, invert())) 
b4 = Button(win, text = str(4+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(4,b4, invert())) 
b5 = Button(win, text = str(5+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(5,b5, invert())) 

b6 = Button(win, text = str(6+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(6,b6, invert())) 
b7 = Button(win, text = str(7+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(7,b7, invert())) 
b8 = Button(win, text = str(8+1), bg= "black", fg= '#ffffff', width = 10, height = 4,command= lambda:transform(8,b8, invert())) 



lll= [
    [b0,b1,b2],
    [b3,b4,b5],
    [b6,b7,b8]
]
def reset():
    global lll,a,t0,alternate
    alternate = 1
    t0.config(bg = '#333', text = '')
    for i in range(Nh):
        for j in range(Nv):
            a[i][j] = '_'
            lll[i][j].config(text = str(3*j + i + 1) )
# for i in range(3):
#     for j in range(3):
#         lll[i][j].config(command=lamTran(i,j)(lll,'X') )

# for i in range(3):
#     for j in range(3):
#         lll[i][j].config(text = str(3*j + i + 1) )
#         
rst = Button(win, text = 'Reset', bg= "green", fg= '#ffffff', width = 9, height = 2 ,command= reset) 


for i in range(Nh):
    for j in range(Nv):
        lll[j][i].place(x = startx +  80*i, y =starty + 70*j)
rst.place(x = startx + 80, y = starty + 70*3)


def show(ll):
    for l in ll:
        print(l)
    print()

def showw(ll):
    print(ll[0],[1,2,3], sep = '  ')
    print(ll[1],[4,5,6], sep = '  ')
    print(ll[2],[7,8,9], sep = '  ')
    print()

def transpose(a):
    return [[a[o][oo] for o in range(3)] for oo in range(3)]
def row_wise(a):
    r0 = a[0]; r1 = a[1]; r2 = a[2];
    b0 = (r0[0]==r0[1]==r0[2] and r0[0] != '_')
    b1 = (r1[0]==r1[1]==r1[2] and r1[0] != '_')
    b2 = (r2[0]==r2[1]==r2[2] and r2[0] != '_')
    return b0 or b1 or b2
def col_wise(a):
    aT = transpose(a)
    return row_wise(aT)
def diagonally(a):
    p1 = (a[0][0] == a[1][1] == a [2][2]  and a[0][0] != '_')
    p2 = (a[2][0] == a[1][1] == a [0][2]  and a[0][2] != '_')
    return p1 or p2

def check(a):
    return row_wise(a) or col_wise(a) or diagonally(a)
def whoWon(a):
    b = copy.deepcopy(a)
    for k in range(3):
        for i in range(3):
            b[i][k] =  b[i][k].replace('O','_')
    # print('Who Won b ?')
    # show(b)
    if(check(b)):
        return 'X'
    return 'O'
def draw(a):
    for l in a:
        if l.count('_'):
            return False
    return not check(a)

global a
a = [['_' for o in range(3)] for oo in range(3)]
showw(a)

# for bl in lll:
#     for b in bl:
#         print(b['command'])
win.mainloop()
'''
for h in range(5):
    
    if(check(a)):
        break;
    print('\nPlayer 1\nEnter the position for the input ')
    alternate = 1 - alternate
    u = int(input());x = (u-1)//3 ; y = (u+2)%3
    item = x; j = y;
    while True:
        if a[x][y]=='_' :
            break;
        print('The cell is already filled\nenter an unfilled cell')
        u = int(input());x = (u-1)//3 ; y = (u+2)%3    
    a[x][y] = 'X'
    lll[x][y].config(text = 'X')
    
    showw(a)
    if(check(a)):
        print('Winner is Player 1 !!!\nCongratulations!!!')
        break;
    elif(draw(a)):
        
        print('The match is a Draw. Play Again.')
        break;

    # Player 2
    print('\nPlayer 2\nEnter the position for the input ')
    u = int(input());x = (u-1)//3 ; y = (u+2)%3
    alternate = 1 - alternate
    while True:
        if a[x][y]=='_' :
            break;
        print('The cell is already filled\nenter an unfilled cell')
        u = int(input());x = (u-1)//3 ; y = (u+2)%3
    a[x][y] = 'O'
    lll[x][y].config(text='O')
    showw(a)
    if(check(a)):
        print('Winner is Player 2 !!!\nCongratulations!!!')
        break;

'''
# b = [[3*oo - o for o in range(3)] for oo in range(3)]

# show(b)
# show(transpose(b))


# for _ in range(int(input())):
#     a = [x for x in input()]
#     b = [x for x in input()]
#     c = [x for x in input()]
#     M =[a,b,c]
#     print(check(M))
'''________________________________'''
'''

def help(a):
    map = dict()
    n = len(a)
    res = n;j=0
    for i in range(n):
        r = n - i - 1
        temp = 0
        if a[i] in map:
            temp = map[a[i]]
        j = max(j,temp)
        map[a[i]] = 1+i
        res = min(res,min(j,r)+j+r)
    return res
        
# cook your dish here
for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    
    print(help(a))
'''