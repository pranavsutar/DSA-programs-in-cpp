
# IManage

points = []
points = [(-10,50),(80,50),(80,-10),(-10,-10)]
d = 10

class Line:
    def __init__(self, x1 = None, y1 = None, x2 = None, y2 = None, m = None, c = None):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        # self.slope = (y2 - y1) / (x2 - x1)
        if x1 == x2:
            self.slope = float('inf')
            self.intercept = x1
        else:
            self.slope = (y2 - y1) / (x2 - x1)
            self.intercept = y1 - self.slope * x1
        
        self.intercept = y1 - self.slope * x1
        self.m = self.slope
        self.c = self.intercept
        if m and c:
            self.m = m
            self.c = c

    def __str__(self):
        if self.slope == float('inf'):
            return f"x = {self.x1}"
        return f"y = {self.m}x + {self.c}"
    
    def __repr__(self):
        if self.slope == float('inf'):
            return f"x = {self.x1}"
        return f"y = {self.m}x + {self.c}"
    
    def __hash__(self):
        return hash((self.m, self.c))
    
    def __eq__(self, other):
        return self.m == other.m and self.c == other.c
    

def find_line(points):
    lines = []
    for i in range(len(points)):
        j = (i+1) % len(points)
        x1, y1 = points[i]
        x2, y2 = points[j]
        
        if x1 == x2:
            lines.append(Line(x1, y1, x2, y2))
        else:
            lines.append(Line(x1, y1, x2, y2))
    return lines

# print(find_line(points))

def find_line_intersection(lines):
    intersections = []
    for i in range(len(lines)):
        for j in range(i+1, len(lines)):
            l1 = lines[i]
            l2 = lines[j]
            if l1.slope == l2.slope:
                continue
            if l1.slope == float('inf'):
                x = l1.x1
                y = l2.m * x + l2.c
            elif l2.slope == float('inf'):
                x = l2.x1
                y = l1.m * x + l1.c
            else:
                x = (l2.c - l1.c) / (l1.m - l2.m)
                y = l1.m * x + l1.c
            intersections.append((x, y))
    return intersections
# y=mx+(c±d√(1+m^2))

def parallel_lines(line, d):
    if line.slope == float('inf'):
        c_ = d*(1+line.m**2)**0.5
        return [Line(m = line.m, c = line.c + c_), Line(m = line.m, c = line.c - c_)]

centroid = (sum(x for x, y in points) / len(points), sum(y for x, y in points) / len(points))

def find_near_centroid(points, d):
    lines = find_line(points)
    ans = []
    parallelLines= [parallel_lines(line, d) for line in lines]

    for i in range(len(parallelLines)):
        j = (i+1) % len(   parallelLines)
        l1 =   parallelLines[i]
        l2 =   parallelLines[j]
        print(l1, l2)

find_near_centroid(points, d)