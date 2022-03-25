'''
Author: Luiz Filipi de Sousa Moura, March 19 2022

Paradigm: Greedy heuristic

Complexity: Sorted has complexity of Ο(n * log n), for is Ο(n), but sorted is not inside the for, so Ο(n * log n) this is the complexity of the algorithm.

Description: Try to put the best value-weight ratio items first.
'''
def knapsack(items, knapsackCapacity):
    value, weight = 0, 0
    for it in sorted(items, key = lambda x: -x[1]/x[0]):
        if weight + it[0] <= knapsackCapacity:
            print("Item in knapsack:", it)
            weight += it[0]
            value += it[1]
    return weight,value

items = [[40,80], [30,100], [30,120]] #weight, value
capacity = 60
print("Peso, Valor total na mochila:", knapsack(items, capacity))
