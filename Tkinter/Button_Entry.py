from tkinter import *

from matplotlib.pyplot import subplot_mosaic
win = Tk()
win.title("Pranav")
# win.iconbitmap('paintbox.ico')

win.minsize(width=1400, height=750)
win.maxsize(width=1800, height=1000)

l = Label(win,text='ToChange')
l.pack()
v = StringVar()
e = Entry(win,textvariable=v)
e.pack()
def change(col = ["yellow", "pink", "red", "green","blue" , "darkblue", "cyan", "yellow","magenta"]):    
    x = v.get()
    print(x)
    l.config(text=x, bg =col[0] )
    col.append(col.pop(0))
b = Button(win,text = 'Submit', bg = 'green', command= change)
b.pack()
win.mainloop()