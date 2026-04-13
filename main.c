#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// ================= QUIZ =================
void jogoQuiz() {
    char opcao;

    do {
        int p, total = 0;

        printf("\n=== PERGUNTAS E RESPOSTAS ===\n");

        printf("\nQuantos aliens o Ben 10 tem?\n");
        printf("1- 10 aliens\n2- 51 aliens\n3- 86 aliens\n4- 62 aliens\nEscolha: ");
        scanf("%d", &p);
        if (p == 4) { printf("Acertou!\n"); total += 20; }
        else printf("Errou! R: 62 aliens\n");

        printf("\nQuem eh o(a) professor(a) mais bonito(a)?\n");
        printf("1- Vitor Hugo\n2- Alessandra\n3- Pedro Girotto\n4- Polyana\nEscolha: ");
        scanf("%d", &p);
        if (p == 3) { printf("Acertou!\n"); total += 20; }
        else printf("Errou! R: Pedro Girotto\n");

        printf("\nQual eh o maior time do Brasil?\n");
        printf("1- flamengo\n2- Paysandu\n3- Remo\n4- Vasco\nEscolha: ");
        scanf("%d", &p);
        if (p == 4) { printf("Acertou!\n"); total += 20; }
        else printf("Errou! R: Vasco\n");

        printf("\nQuantos paises ha na America do Sul?\n");
        printf("1- 11\n2- 12\n3- 13\n4- 10\nEscolha: ");
        scanf("%d", &p);
        if (p == 2) { printf("Acertou!\n"); total += 20; }
        else printf("Errou! R: 12\n");

        printf("\nQuantos ml tem 1 litro?\n");
        printf("1- 1000\n2- 800\n3- 10\n4- 100\nEscolha: ");
        scanf("%d", &p);
        if (p == 1) { printf("Acertou!\n"); total += 20; }
        else printf("Errou! R: 1000\n");

        printf("\nPontuacao total: %d\n", total);

        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's');
}

// ================= COBRA NA CAIXA =================
void jogoCobra() {
    char opcao;
    srand(time(NULL));

    do {
        int cobra, botao, vez, escolha, escolha_anterior=0, p1, p2;
       
        char *nomep1, *nomep2;

        char nome1[50] = "Joscledio\n";
        char nome2[50] = "Manhatan\n";
        char nome3[50] = "Klebs\n";
        char nome4[50] = "Nhe\n";
        char nome5[50] = "Pou\n";
        char nome6[50] = "O Destruidor de Mundos\n";
        char nome7[50] = "O Todo Poderoso\n";

        printf("=== COBRA NA CAIXA (2 JOGADORES) ===\n\n");
        printf("Escolha os nomes:\n");
        printf("1.Joscledio\n2.Manhatan\n3.Klebs\n4.Nhe\n5.Pou\n6.Destruidor de Mundos\n7.O Todo Poderoso\n\n");

        // Jogador 1
        do {
            printf("Jogador 1: ");
            scanf("%d", &p1);

            if (p1 == 1) nomep1 = nome1;
            else if (p1 == 2) nomep1 = nome2;
            else if (p1 == 3) nomep1 = nome3;
            else if (p1 == 4) nomep1 = nome4;
            else if (p1 == 5) nomep1 = nome5;
            else if (p1 == 6) nomep1 = nome6;
            else if (p1 == 7) nomep1 = nome7;
            else printf("\nNome invalido!\n");
        } while (p1 < 1 || p1 > 7);

        // Jogador 2
        do {
            printf("Jogador 2: ");
            scanf("%d", &p2);

            if (p2 == 1) nomep2 = nome1;
            else if (p2 == 2) nomep2 = nome2;
            else if (p2 == 3) nomep2 = nome3;
            else if (p2 == 4) nomep2 = nome4;
            else if (p2 == 5) nomep2 = nome5;
            else if (p2 == 6) nomep2 = nome6;
            else if (p2 == 7) nomep2 = nome7;
            else printf("Nome invalido!");
        } while (p2 < 1 || p2 > 7);

        printf("Jogador 1: %s", nomep1);
        printf("Jogador 2: %s", nomep2);

        // Sorteio
        do {
            cobra = rand() % 5 + 1;
            botao = rand() % 5 + 1;
        } while (cobra == botao);

        printf("===== JOGO DA CAIXA =====\n");

        while (1) {
            vez = rand() % 2 + 1;

            char *jogadorAtual = (vez == 1) ? nomep1 : nomep2;

            printf("Vez de %s\n", jogadorAtual);

            for (int i = 1; i <= 5; i++) {
                printf("%d [*****]\n  [*****]\n  [*****]\n\n", i);
            }

            printf("Escolha uma caixa (1-5): ");
            scanf("%d", &escolha);

            if (escolha == escolha_anterior) {
                printf("\nVoce ja escolheu essa!\n");
                continue;
            }

            if (escolha < 1 || escolha > 5) {
                printf("\nNao existem outras caixas alem dessas abestado!n");
                continue;
            }

            escolha_anterior = escolha;

            if (escolha == cobra) {
                printf("%s encontrou a COBRA! Perdeu!", jogadorAtual);
                break;
            } else if (escolha == botao) {
                printf("%s VOCE ENCONTROU O BOTAO E SAIU DA TUMBA !!!!!!!!!", jogadorAtual);
                break;
            } else {
                printf("Caixa vazia...");
            }
        }

        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's');
}

// ================= GOUSMAS WAR =================
typedef struct {
    int furia;
    bool ativa;
} Gousma;

typedef struct {
    Gousma gousmas[2];
} Jogador;

void iniciarPartida(Jogador jogadores[]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            jogadores[i].gousmas[j].furia = 1;
            jogadores[i].gousmas[j].ativa = true;
        }
    }
}

void exibirMesa(Jogador jogadores[]) {
    printf("====================================\n");
    for (int i = 0; i < 2; i++) {
        printf("--- JOGADOR %d ---\n", i + 1);
        for (int j = 0; j < 2; j++) {
            if (jogadores[i].gousmas[j].ativa) {
                printf("  Gousma %d: [Furia: %d]\n", j + 1, jogadores[i].gousmas[j].furia);
            } else {
                printf("  Gousma %d: [DESTRUIDA]\n", j + 1);
            }
        }
    }
    printf("====================================\n");
}

bool verificarVitoria(Jogador jogadores[]) {
    bool j1Perdeu = !jogadores[0].gousmas[0].ativa && !jogadores[0].gousmas[1].ativa;
    bool j2Perdeu = !jogadores[1].gousmas[0].ativa && !jogadores[1].gousmas[1].ativa;

    if (j1Perdeu) {
        printf("** JOGADOR 2 VENCEU! **");
        return true;
    } else if (j2Perdeu) {
        printf("** JOGADOR 1 VENCEU! **");
        return true;
    }
    return false;
}

void jogoGousmas() {
    char opcao;

    do {
        Jogador jogadores[2];
        iniciarPartida(jogadores);

        int turno = 0;
        bool fimDeJogo = false;

        while (!fimDeJogo) {
            exibirMesa(jogadores);

            printf("Turno do JOGADOR %d\n", turno + 1);
            printf("1 - Atacar  2 - Dividir Furia\nEscolha: ");

            int acao;
            scanf("%d", &acao);

            int inimigo = 1 - turno;

            if (acao == 1) {
                int atacante, alvo;

                printf("Escolha sua Gousma (1 ou 2): ");
                scanf("%d", &atacante);
                atacante--;

                if (atacante < 0 || atacante > 1 || !jogadores[turno].gousmas[atacante].ativa) {
                    printf("\nGousma invalida!\n");
                    continue;
                }

                printf("Escolha o alvo inimigo (1 ou 2): \n\n");
                scanf("%d", &alvo);
                alvo--;

                if (alvo < 0 || alvo > 1 || !jogadores[inimigo].gousmas[alvo].ativa) {
                    printf("\nAlvo invalido!\n");
                    continue;
                }

                int forca = jogadores[turno].gousmas[atacante].furia;
                jogadores[inimigo].gousmas[alvo].furia += forca;

                printf("Ataque! +%d de furia no inimigo\n", forca);

                if (jogadores[inimigo].gousmas[alvo].furia > 5) {
                    jogadores[inimigo].gousmas[alvo].ativa = false;
                    printf("A Gousma inimiga explodiu!");
                }

            } else if (acao == 2) {
                int doador, quantidade;

                printf("Qual Gousma vai doar? (1 ou 2): ");
                scanf("%d", &doador);
                doador--;

                if (doador < 0 || doador > 1 || !jogadores[turno].gousmas[doador].ativa || jogadores[turno].gousmas[doador].furia < 2) {
                    printf("\nDoacao invalida!\n");
                    continue;
                }

                int receptor = 1 - doador;

                printf("Quantidade de furia: ");
                scanf("%d", &quantidade);

                if (quantidade < 1 || quantidade >= jogadores[turno].gousmas[doador].furia) {
                    printf("\nQuantidade invalida!\n");
                    continue;
                }

                jogadores[turno].gousmas[doador].furia -= quantidade;

                if (!jogadores[turno].gousmas[receptor].ativa) {
                    jogadores[turno].gousmas[receptor].furia = quantidade;
                    jogadores[turno].gousmas[receptor].ativa = true;
                    printf("Gousma revivida!");
                } else {
                    jogadores[turno].gousmas[receptor].furia += quantidade;
                    printf("Transferencia feita!");
                }

                if (jogadores[turno].gousmas[receptor].furia > 5) {
                    jogadores[turno].gousmas[receptor].ativa = false;
                    printf("Explodiu por excesso de furia!");
                }

            } else {
                printf("\nAcao invalida!\n");
                continue;
            }

            fimDeJogo = verificarVitoria(jogadores);

            if (!fimDeJogo) {
                turno = 1 - turno;
            }
        }

        printf("Jogar novamente? (s/n): ");
        scanf(" %c", &opcao);

    } while (opcao == 's');
}

// ================= MAIN =================
int main() {
    int escolha;
    char novamente;

    do {
        printf("\n=== JOGOS OFFLINE ===\n");
        printf("1- Perguntas e respostas\n2- Cobra na caixa\n3- Gousmas war\n4- Sair\nEscolha: ");
        scanf("%d", &escolha);

        if (escolha == 1) jogoQuiz();
        else if (escolha == 2) jogoCobra();
        else if (escolha == 3) jogoGousmas();
        else if (escolha == 4) break;
        else printf("Opcao invalida!\n");

        printf("\nEscolher outro jogo? (s/n): ");
        scanf(" %c", &novamente);

    } while (novamente == 's');

    printf("Saindo...\n");
    return 0;
}
