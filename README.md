# ARVORE-RB

Código referente a árvore RB, também conhecida como rubro-negra sua estrutura e explicações importantes!

É interessante que você case os estudos com o simulador online, ele facilita a visualização dos processos, além disso, é de suma importância treinar na folha!

Simulador RB: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html

Como funciona:

* Cor de cada nó: Cada nó da árvore é colorido de vermelho ou preto.

* Raiz preta: A raiz da árvore é sempre preta.

* Folhas NULL são pretas: Todas os nós com filhos NULL são consideradas pretas e são chamadas de folhas.

* Vermelhos não são adjacentes: Se um nó é vermelho, então ambos os seus filhos são pretos (ou seja, não são permitidos dois nós vermelhos consecutivos na mesma linha de descendência).

* Igualdade de caminhos pretos: Para cada nó, todos os caminhos simples daquele nó até os nós descendentes que são folhas contêm o mesmo número de nós pretos.

* Além dessas regras, as operações de inserção e remoção em uma árvore rubro-negra requerem procedimentos específicos para reequilibrar a árvore, caso alguma das regras seja violada. Esses procedimentos envolvem rotações (simples e duplas) e alterações de cores dos nós para restaurar as propriedades da árvore rubro-negra após uma inserção ou remoção.

Rotacionando Nós:

* Rotação à esquerda: A rotação à esquerda em um nó X significa fazer o nó à direita de X (digamos Y) tornar-se o novo pai de X, onde X passa a ser o filho esquerdo de Y, e o filho esquerdo original de Y passa a ser o filho direito de X.

* Rotação à direita: É o inverso da rotação à esquerda. A rotação à direita em um nó X faz o nó à esquerda de X (digamos Y) tornar-se o novo pai de X, onde X passa a ser o filho direito de Y, e o filho direito original de Y passa a ser o filho esquerdo de X.

Para leitura complementar:

Leitura do capítulo 13 (Árvores Vermelho-Preto) do livro:

Algoritmos: teoria e prática. Thomas H. Cormen... [et al.];
tradução da segunda edição [americana] Vandenberg D. de Souza.
Rio de Janeiro. Elsevier. 2002.

Vídeo Aulas:

5.16 Red Black tree | Introduction to Red Black trees | DSA Tutorials Jenny's Lectures CS IT

https://youtu.be/3RQtq7PDHog?list=PL2NFNH-W1DQPhYEJ0oZh09wzpk7nBv3Xk

5.18 Red Black Tree Insertion | DSA Tutorials for Beginners Tutorials Jenny's Lectures CS IT

https://youtu.be/qA02XWRTBdw

5.18 Red Black Tree Deletion | DSA Tutorials for Beginners Tutorials Jenny's Lectures CS IT

https://youtu.be/w5cvkTXY0vQ

Red Black Tree Deletion | Tushar Roy

https://youtu.be/CTvfzU_uNKE


Exercício para fins de estudo:

![exercicio_page-0001](https://github.com/ViniciusLeiteCosta/ARVORE-RB/assets/92338016/295db69c-23ab-48c4-ad01-1e4c9f75b3b0)
