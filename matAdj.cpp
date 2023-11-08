#include <iostream>

class Graph
{
private:
    int vertexes;
    int **mat;

public:
    Graph(int vertexes) : vertexes(vertexes)
    {
        mat = new int *[vertexes];
        for (int i = 0; i < vertexes; i++)
        {
            mat[i] = new int[vertexes];
            for (int j = 0; j < vertexes; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    ~Graph()
    {
        for (int i = 0; i < vertexes; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void printGraph()
    {
        for (int i = 0; i < vertexes; i++)
        {
            for (int j = 0; j < vertexes; j++)
            {
                std::cout << this->mat[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    void connectVertexes(bool is_targeted)
    {
        std::cout << "Insira as conexões dos vértices:" << '\n';
        for (int i = 0; i < this->vertexes; i++)
        {
            for (int j = 0; j < this->vertexes; j++)
            {
                if (is_targeted || i <= j)
                {
                    std::cout << i << "---->" << j << " ? (1 para sim, 0 para não): ";
                    int isConnected;
                    std::cin >> isConnected;
                    if (isConnected == 1)
                    {
                        int edges;
                        std::cout << "Quantas arestas? ";
                        std::cin >> edges;
                        mat[i][j] = edges;
                        if (!is_targeted)
                        {
                            mat[j][i] = edges;
                        }
                    }
                }
            }
        }
    }

    void connectWeightedEdges(bool is_targeted)
    {
        for (int i = 0; i < this->vertexes; i++)
        {
            for (int j = 0; j < this->vertexes; j++)
            {
                if (is_targeted || i <= j)
                {
                    std::cout << i << "---->" << j << " ? (1 para sim, 0 para não): ";
                    int isConnected;
                    std::cin >> isConnected;
                    if (isConnected == 1)
                    {
                        int value;
                        std::cout << "Insira o valor da aresta: ";
                        std::cin >> value;
                        mat[i][j] = value;
                        if (!is_targeted)
                        {
                            mat[j][i] = value;
                        }
                    }
                }
            }
        }
    }

    bool isCompleteGraph()
    {
        for (int i = 0; i < this->vertexes; i++)
        {
            for (int j = 0; j < this->vertexes; j++)
            {
                if (i != j && mat[i][j] != 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isMultiGraph()
    {
        for (int i = 0; i < vertexes; i++)
        {
            for (int j = 0; j < vertexes; j++)
            {
                if (mat[i][j] > 1)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int countLoops()
    {
        int loopCount = 0;
        for (int i = 0; i < vertexes; i++)
        {
            if (mat[i][i] > 0)
            {
                loopCount++;
            }
        }
        return loopCount;
    }

    int countLeafVertices()
    {
        int leafCount = 0;
        for (int i = 0; i < vertexes; i++)
        {
            int degree = 0;
            for (int j = 0; j < vertexes; j++)
            {
                degree += mat[i][j];
            }
            if (degree == 1)
            {
                leafCount++;
            }
        }
        return leafCount;
    }

    bool hasIsolatedVertex()
    {
        for (int i = 0; i < vertexes; i++)
        {
            bool isolated = true;
            for (int j = 0; j < vertexes; j++)
            {
                if (mat[i][j] != 0)
                {
                    isolated = false;
                    break;
                }
            }
            if (isolated)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    int option;
    Graph *graph = nullptr;
    bool isGraphGenerated = false;

    while (true)
    {

        std::cout << "Menu:" << std::endl;
        std::cout << "1 - Gerar grafo" << std::endl;
        std::cout << "2 - Verificar se é um multigrafo" << std::endl;
        std::cout << "3 - Verificar se é completo" << std::endl;
        std::cout << "4 - Quantos laços existem" << std::endl;
        std::cout << "5 - Quantos vértices folhas existem" << std::endl;
        std::cout << "6 - Verificar se existe vértice isolado" << std::endl;
        std::cout << "7 - Ver Grafo" << std::endl;
        std::cout << "8 - Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
        {
            if (graph)
            {
                delete graph;
            }
            int vertexes;
            char value;
            bool is_targeted;
            bool is_weighted;

            std::cout << "Insira a quantidade de vértices: ";
            std::cin >> vertexes;

            do
            {
                std::cout << "O grafo é direcionado (y/n)? ";
                std::cin >> value;

                if (value == 'y')
                {
                    is_targeted = true;
                }
                else if (value == 'n')
                {
                    is_targeted = false;
                }
            } while (value != 'y' && value != 'n');

            graph = new Graph(vertexes);
            value = ' ';

            do
            {
                std::cout << "O grafo é ponderado? (y/n)? ";
                std::cin >> value;
                if (value == 'y')
                {
                    is_weighted = true;
                }
                else if (value == 'n')
                {
                    is_weighted = false;
                }
            } while (value != 'y' && value != 'n');

            if (is_weighted)
            {
                graph->connectWeightedEdges(is_targeted);
            }
            else
            {
                graph->connectVertexes(is_targeted);
            }
            isGraphGenerated = true;
            break;
        }
        case 2:
        {
            if (isGraphGenerated)
            {
                if (graph->isMultiGraph())
                {
                    std::cout << "O grafo é um multigrafo." << std::endl;
                }
                else
                {
                    std::cout << "O grafo não é um multigrafo." << std::endl;
                }
            }
            else
            {
                std::cout << "Gere um grafo primeiro." << std::endl;
            }
            break;
        }
        case 3:
        {
            if(isGraphGenerated){
                if(graph->isCompleteGraph()){
                    std::cout << "O grafo é completo";
                }
            }
            break;
        }
        case 4:
        {
            if (isGraphGenerated)
            {
                int loops = graph->countLoops();
                std::cout << "Número de laços: " << loops << std::endl;
            }
            else
            {
                std::cout << "Gere um grafo primeiro." << std::endl;
            }
            break;
        }
        case 5:
        {
            if (isGraphGenerated)
            {
                int leafVertices = graph->countLeafVertices();
                std::cout << "Número de vértices folhas: " << leafVertices << std::endl;
            }
            else
            {
                std::cout << "Gere um grafo primeiro." << std::endl;
            }
            break;
        }
        case 6:
        {
            if (isGraphGenerated)
            {
                if (graph->hasIsolatedVertex())
                {
                    std::cout << "Existe pelo menos um vértice isolado." << std::endl;
                }
                else
                {
                    std::cout << "Não existem vértices isolados." << std::endl;
                }
            }
            else
            {
                std::cout << "Gere um grafo primeiro." << std::endl;
            }
            break;
        }
        case 7:
        {
            if (graph)
            {
                graph->printGraph();
            }
            break;
        }
        case 8:
        {
            if (graph)
            {
                delete graph;
            }
            return 0;
        }
        default:
        {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
        }
    }

    return 0;
}