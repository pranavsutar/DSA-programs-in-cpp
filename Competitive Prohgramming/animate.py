import numpy as np, matplotlib.pyplot as plt
from scipy.integrate import odeint

# 2D

N = 3
G = 1.0

posi = [np.random.uniform(-1,1,2) for i in range(N)]
veli = [np.random.uniform(-1,1,2) for i in range(N)]
mass = np.random.uniform(0.1,1,N)

# print info
# positions:
print('Positions:')
for i in range(N):
    print

def grav(state,t):
    x = state[:N]
    y = state[N:2*N]
    vx = state[2*N:3*N]
    vy = state[3*N:]
    dx = np.zeros(N)
    dy = np.zeros(N)
    for i in range(N):
        for j in range(N):
            if i!=j:
                dx[i] += G*mass[j]*(x[j]-x[i])/np.hypot(x[j]-x[i],y[j]-y[i])**3
                dy[i] += G*mass[j]*(y[j]-y[i])/np.hypot(x[j]-x[i],y[j]-y[i])**3
    return np.concatenate((vx,vy,dx,dy))

state0 = np.concatenate((posi[0],posi[1],veli[0],veli[1]))

t = np.linspace(0,15,1001)
state = odeint(grav,state0,t)
# also plot the trajectory of the first particle

from matplotlib.animation import FuncAnimation

fig, ax = plt.subplots()
lim = 5
ax.set_xlim(-lim,lim)
ax.set_ylim(-lim,lim)
ax.set_aspect('equal')
ax.grid()
line, = ax.plot([],[],'o',color='r')
line2, = ax.plot([],[],'o',color='b')


# inform about the mass of the particles
for i in range(N):
    ax.text(state0[i],state0[i+N],(mass[i]).__str__()[:4])

    

def animate(i):
    line.set_data(state[i,:N],state[i,N:2*N])
    line2.set_data(state[i,0],state[i,N])
    return line,line2

ani = FuncAnimation(fig,animate,frames=1001,interval=1,blit=True)
plt.show()