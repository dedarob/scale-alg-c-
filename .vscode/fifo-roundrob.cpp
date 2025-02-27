#include <iostream>
#include <map>

void fazerFifo(std::map<int, int> &dadosMap)
{
    int tempoProcessTotal = 0;
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
    return false;
}

void fazerRobin(std::map<int, int> dadosMap)
{
    std::map<int, int> originalMap = dadosMap;
    std::cout << "---começando robin" << std::endl;
    int tempoProcessTotal = 0;

    while (checarCondicao(dadosMap))
    {
        for (auto &i : dadosMap)
        {
            int valor = i.second;
            if (valor <= 0)
            {
                continue;
            }

            std::cout << "processando " << i.first << "... tamanho " << i.second << std::endl;
            if (valor <= 2)
            {
                i.second = 0;
            }
            else
            {
                i.second -= 2;
            }

            int porcent = ((originalMap.at(i.first) - i.second) * 100) / originalMap.at(i.first);
            tempoProcessTotal += 4;

            std::cout << "dado " << i.first << " está sendo processado e está em " << porcent << "%" << std::endl;

            if (i.second == 0)
            {
                std::cout << "dado " << i.first << " foi processado" << std::endl;
            }
        }
    }
    std::cout << "todos os dados concluidos com o tempo de " << tempoProcessTotal << std::endl;
    std::cout << "---robin terminado--- \n\n\n";
}

int main()
{
    std::map<int, int> dadosMap;

    dadosMap[1] = 8;
    dadosMap[2] = 15;
    dadosMap[3] = 9;
    fazerFifo(dadosMap);
    fazerRobin(dadosMap);

    return 0;
}
