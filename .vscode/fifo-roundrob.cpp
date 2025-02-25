#include <iostream>
#include <map>

void fazerFifo(std::map<int, int> &dadosMap)
{
    int tempoProcessTotal;
    std::cout << "---começando fifo" << std::endl;
    for (auto i : dadosMap)
    {
        std::cout << "processando dado: " << i.first << std::endl;
        int tempoProcessamento = i.second / 2;
        tempoProcessTotal += tempoProcessamento;
        std::cout << "dado " << i.first << " foi processado e demorou " << tempoProcessamento << std::endl;
    }
    std::cout << "todos os dados concluidos com o tempo de " << tempoProcessTotal << std::endl;
    std::cout << "---fifo terminado--- \n\n\n"
              << std::endl;
}

bool checarCondicao(const std::map<int, int> &dadosMap)
{
    for (const auto i : dadosMap)
    {
        if (i.second > 0)
        {
            return true;
        }
    }
}

void fazerRobin(std::map<int, int> dadosMap)
{
    std::cout << "---começando robin" << std::endl;
    int tempoProcessTotal;
    while ((checarCondicao))
    {
        // TODO: verificar se a solução usando o metodo checarCondicao não é O(n^2)
        //  e tambem terminar a logica do robin
    }
}

int main()
{
    std::map<int, int> dadosMap;

    dadosMap[1] = 8;
    dadosMap[2] = 15;
    dadosMap[3] = 9;
    fazerFifo(dadosMap);
}