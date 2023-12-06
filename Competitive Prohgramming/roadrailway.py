# travelling salesman problem

import random

class City:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, city):
        xDistance = abs(self.x - city.x)
        yDistance = abs(self.y - city.y)
        distance = (xDistance ** 2 + yDistance ** 2) ** 0.5
        return distance

    def __repr__(self):
        return "(" + str(self.x) + "," + str(self.y) + ")"
    
class Route:
    def __init__(self, route, distance=0.0):
        self.route = route
        self.distance = distance
        self.fitness = 0.0

    def __len__(self):
        return len(self.route)

    def __getitem__(self, index):
        return self.route[index]

    def __setitem__(self, key, value):
        self.route[key] = value

    def __repr__(self):
        geneString = ""
        for i in range(0, len(self.route)):
            geneString += str(self.route[i]) + ","
        return geneString

    def getDistance(self):
        if self.distance == 0:
            pathDistance = 0
            for i in range(0, len(self.route)):
                fromCity = self.route[i]
                destinationCity = None
                if i + 1 < len(self.route):
                    destinationCity = self.route[i + 1]
                else:
                    destinationCity = self.route[0]
                pathDistance += fromCity.distance(destinationCity)
            self.distance = pathDistance
        return self.distance

    def getFitness(self):
        if self.fitness == 0:
            self.fitness = 1 / float(self.getDistance())
        return self.fitness
    
def createRoute(cityList):
    route = random.sample(cityList, len(cityList))
    return Route(route)

def initialPopulation(popSize, cityList):
    population = []
    for i in range(0, popSize):
        population.append(createRoute(cityList))
    return population

def rankRoutes(population):
    fitnessResults = {}
    for i in range(0, len(population)):
        fitnessResults[i] = population[i].getFitness()
    return sorted(fitnessResults.items(), key = lambda x: x[1], reverse = True)

def selection(popRanked, eliteSize):
    selectionResults = []
    df = {}
    for i in range(0, eliteSize):
        selectionResults.append(popRanked[i][0])
    for i in range(0, len(popRanked) - eliteSize):
        df[i] = popRanked[i][1]
    for i in range(0, len(popRanked) - eliteSize):
        pick = 100 * random.random()
        for key, value in df.items():
            if pick <= value:
                selectionResults.append(key)
                break
            pick = pick - value
    return selectionResults


def matingPool(population, selectionResults):
    matingpool = []
    for i in range(0, len(selectionResults)):
        index = selectionResults[i]
        matingpool.append(population[index])
    return matingpool

def breed(parent1, parent2):
    child = []
    childP1 = []
    childP2 = []
    geneA = int(random.random() * len(parent1))
    geneB = int(random.random() * len(parent1))
    startGene = min(geneA, geneB)
    endGene = max(geneA, geneB)
    for i in range(startGene, endGene):
        childP1.append(parent1[i])
    childP2 = [item for item in parent2 if item not in childP1]
    child = childP1 + childP2
    return Route(child)

def breedPopulation(matingpool, eliteSize):
    children = []
    length = len(matingpool) - eliteSize
    pool = random.sample(matingpool, len(matingpool))
    for i in range(0, eliteSize):
        children.append(matingpool[i])
    for i in range(0, length):
        child = breed(pool[i], pool[len(matingpool)-i-1])
        children.append(child)
    return children

def mutate(individual, mutationRate):
    for swapped in range(len(individual.route)):
        if(random.random() < mutationRate):
            swapWith = int(random.random() * len(individual.route))
            city1 = individual.route[swapped]
            city2 = individual.route[swapWith]
            individual.route[swapped] = city2
            individual.route[swapWith] = city1
    return individual

def mutatePopulation(population, mutationRate):
    mutatedPop = []
    for ind in range(0, len(population)):
        mutatedInd = mutate(population[ind], mutationRate)
        mutatedPop.append(mutatedInd)
    return mutatedPop

def nextGeneration(currentGen, eliteSize, mutationRate):
    popRanked = rankRoutes(currentGen)
    selectionResults = selection(popRanked, eliteSize)
    matingpool = matingPool(currentGen, selectionResults)
    children = breedPopulation(matingpool, eliteSize)
    nextGeneration = mutatePopulation(children, mutationRate)
    return nextGeneration

def geneticAlgorithm(population, popSize, eliteSize, mutationRate, generations):
    pop = initialPopulation(popSize, population)
    print("Initial distance: " + str(1 / rankRoutes(pop)[0][1]))
    for i in range(0, generations):
        pop = nextGeneration(pop, eliteSize, mutationRate)
    print("Final distance: " + str(1 / rankRoutes(pop)[0][1]))
    bestRouteIndex = rankRoutes(pop)[0][0]
    bestRoute = pop[bestRouteIndex]
    return bestRoute

n, m = map(int, input().split())
AdjList = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    AdjList[u].append((v, w))
    AdjList[v].append((u, w))

# print minimum distance from 0 to n-1, and -1 if no path exists
