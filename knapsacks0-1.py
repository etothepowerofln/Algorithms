'''
Author: Luiz Filipi de Sousa Moura, March 19 2022.

Paradigm: Dynamic programming.

Complexity: Ο(Nk * Ni * C), where Nk is the number of knapsacks, Ni is the number of items and C is the capacity of the larger knapsack.

Description: A 0-1 knapsack problem, but with N knapsacks. Also recovering the weight of the items in the knapsack in the end.
'''
def knapSack(capacities, weights, values, nItems):
    totalGain = 0
    for i in range(len(values)):
        totalGain += values[i]
    print("Max possible gain:", totalGain)
    
    #iterate for each knapsack
    for y in range(len(capacities)):
        wtsIn = []
        wtsNotIn = weights.copy()
        
        #core knapsack problem
        K = [[0 for x in range(capacities[y] + 1)] for x in range(nItems + 1)]
        for i in range(nItems + 1):
            for c in range(capacities[y] + 1):
                if i == 0 or c == 0:
                    K[i][c] = 0
                elif weights[i-1] <= c:
                    K[i][c] = max(values[i-1] + K[i-1][c-weights[i-1]], K[i-1][c])
                else:
                    K[i][c] = K[i-1][c]
  
        print("\nKnapsack", y+1, "/", len(capacities))
        print("Total value in knapsack:", K[nItems][c])
        print("Total value not in knapsack:", totalGain - K[nItems][c])
        
        #retrieve weights
        w = capacities[y]
        for i in range(n, 0, -1):
            if K[nItems][c] <= 0:
                break
            if K[nItems][c] == K[i - 1][w]:
                continue
            else:
                if weights[i-1] not in wtsIn: wtsIn.append(weights[i - 1])
                if weights[i-1] in wtsNotIn: wtsNotIn.remove(weights[i - 1])
                K[nItems][c] = K[nItems][c] - values[i - 1]
                w = w - weights[i - 1]
                
        print("Weight of each item in knapsack:", wtsIn)
        print("Weight of items not in knapsack:", wtsNotIn)

z = [200, 100, 150] #capacity of each knapsack
w = [3, 6, 9, 12, 15, 20, 30, 35, 40, 45] #weight of each item
v = [10, 20, 30, 35, 40, 45, 50, 55, 60, 65] #value of each item
if len(w) == len(v):
    n = len(v)
    knapSack(z, w, v, n)
else: print("Number of item weights and item values do not match.")
