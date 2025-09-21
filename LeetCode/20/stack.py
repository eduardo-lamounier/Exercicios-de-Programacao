'''
20. Validid Parentheses - Easy
|https://leetcode.com/problems/valid-parentheses/
Topics:
|String, Stack
'''

class Solution:
    def isValid(self, s: str) -> bool:
        # Fechamento de parênteses e suas respectivas aberturas
        brackets = {
            ')' : '(',
            ']' : '[',
            '}' : '{'
        }

        stack = [] # Armazena os parênteses para serem fechados posteriormente

        for ch in s:
            if not ch in brackets:
                # Se o caractere for uma abertura de parêntese, é adicionado na
                # stack:
                stack.append(ch)
                continue

            # Caso o caractere seja o fechamento de um parêntese:
            if not stack or stack.pop() != brackets[ch]:
                # Fechamento de um parêntese que não foi aberto ou fechamento 
                # do parêntese errado, ou seja, string é inválida:
                return False
        
        return not stack # Se restarem parênteses não fechados, string é
                         # inválida