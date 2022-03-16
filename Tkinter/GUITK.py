from tkinter import *

win = Tk()
win.title("Pranav")
# win.iconbitmap('paintbox.ico')
win.maxsize(width=1800, height=1000)
win.maxsize(width=1800, height=1000)

# Labels
lbl = Label(win, text = "User Name", bg= "blue", fg= 'white', width = 10)
## pack-
# lbl.pack()
## grid-
# lbl.grid(row = 3, column= 3)
## place
 
# lbl.place(x = 700, y = 200 )
lbl.place(x = 10, y = 100 )

var = StringVar()
## Entry Box
ent = Entry(win,textvariable= var, width= 10, bg = 'yellow', fg = 'black')
ent.place(x = 90, y = 100)

## Button
btn = Button(win, text = 'Submit', bg = 'light green', fg = 'black' )
btn.place(x = 20, y = 120)
win.mainloop() 
