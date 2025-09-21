'''
1. Two Sum - Easy
|https://leetcode.com/problems/two-sum/description/
Topics:
|Array, Hash Table
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        occ = {} # Hash map para armazenar as posições dos elementos que já
                 # apareceram

        for i, num in enumerate(nums):
            diff = target - num # Valor que precisa ser somado ao atual para
                                # resultar em 'target'

            if diff in occ: 
                # Se já tivermos passado pelo valor necessário, retorna sua
                # posição e a posição atual:
                return [occ[diff], i]
            occ[num] = i # Caso contrário, simplesmente adiciona a posição
        
        # Não é necessário checar pelos valores à frente da posição i, visto
        # que o valor que somaria com o da posição i, se ele existir, já vai
        # procurar pelo valor em i posteriormente no laço de repetição