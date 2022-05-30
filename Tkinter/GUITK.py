from tkinter import *
win = Tk()
win.title("Pranav")
# win.iconbitmap('paintbox.ico')

win.minsize(width=1400, height=750)
win.maxsize(width=1800, height=1000)
# Labels
# l1 = 
Nh =15
Nv =25
startx = 0
starty = 0
# ll1 = [Label(win, text = "T" + str(i), bg= "blue", fg= 'white', width = 10, height= 1) for i in range(6)]
# ll2 = [Label(win, text = "U" + str(i), bg= "black", fg= 'white', width = 10, height= 1) for i in range(6)]
# for i in range(6):
#     ll1[i].place(x = 10, y = 100+25*i)
#     ll2[i].place(x = 90, y = 100+25*i)

lll = [[Label(win, text = "T" + str(item+1) + str(j+1), bg= "black", fg= 'white', width = 14, height = 1) for item in range(Nv) ] for j in range(Nh)]

for i in range(Nh):
    for j in range(Nv):
        lll[i][j].place(x = startx +  106*i, y =starty + 25*j)

'''
Hoz:
80-10
85-11
92-12
101-13
109-14(106 also)
'''

'''var = StringVar()
## Entry Box
ent = Entry(win,textvariable= var, width= 10, bg = 'yellow', fg = 'black')
ent.place(x = 90, y = 100)

## Button
btn = Button(win, text = 'Submit', bg = 'light green', fg = 'black' )
btn.place(x = 20, y = 120)

'''
win.mainloop() 