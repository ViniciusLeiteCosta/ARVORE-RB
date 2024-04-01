# ARVORE-RB
Código referente a árvore RB, também conhecida como rubro-negra sua estrutura e explicações importantes!

Como funciona:

Cor de cada nó: Cada nó da árvore é colorido de vermelho ou preto.

Raiz preta: A raiz da árvore é sempre preta.

Folhas NULL são pretas: Todas os nós com filhos NULL são consideradas pretas e são chamadas de folhas.

Vermelhos não são adjacentes: Se um nó é vermelho, então ambos os seus filhos são pretos (ou seja, não são permitidos dois nós vermelhos consecutivos na mesma linha de descendência).

Igualdade de caminhos pretos: Para cada nó, todos os caminhos simples daquele nó até os nós descendentes que são folhas contêm o mesmo número de nós pretos.

Além dessas regras, as operações de inserção e remoção em uma árvore rubro-negra requerem procedimentos específicos para reequilibrar a árvore, caso alguma das regras seja violada. Esses procedimentos envolvem rotações (simples e duplas) e alterações de cores dos nós para restaurar as propriedades da árvore rubro-negra após uma inserção ou remoção.

Rotacionando Nós:

Rotação à esquerda: A rotação à esquerda em um nó X significa fazer o nó à direita de X (digamos Y) tornar-se o novo pai de X, onde X passa a ser o filho esquerdo de Y, e o filho esquerdo original de Y passa a ser o filho direito de X.

Rotação à direita: É o inverso da rotação à esquerda. A rotação à direita em um nó X faz o nó à esquerda de X (digamos Y) tornar-se o novo pai de X, onde X passa a ser o filho direito de Y, e o filho direito original de Y passa a ser o filho esquerdo de X.
