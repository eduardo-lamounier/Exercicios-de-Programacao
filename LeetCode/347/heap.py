'''
347. Top K Frequent Elements - Medium
|https://leetcode.com/problems/top-k-frequent-elements/description/
Topics:
|Array, Hash Table, Divide and Conquer, Sorting, Heap, Bucket Sort, Counting, 
|Quickselect
'''

import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {} # Hash map para guardar a frequência de cada número
        for num in nums:
            count[num] = count.get(num, 0) + 1 # Incrementa a frequência do
                                               # número 'num'
        
        heap = [] # Max Heap
        for num, freq in count.items(): # Passa por cada par (key, val) do
                                        # contador
            # Adiciona o número na heap, tendo sua prioridade definida pela sua
            # frequência:
            heapq.heappush(heap, [-1*freq, num]) # inverte-se o sinal para que
                                                 # os valores com maior
                                                 # frequência fiquem no topo
        
        res = [] # Armazena os k elementos que mais aparecem no array
        for i in range(k):
            res.append(heapq.heappop(heap)[1]) # Adiciona o número com maior
                                               # frequência da heap
        
        return res
