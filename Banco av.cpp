#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define USER_PASSWORD "12345"
#define ADMIN_PASSWORD "12345"

typedef struct {
    char agencia[100];
    char numero_conta[100];
    char nome_cliente[100];
    char cpf[100];
    char data_nascimento[100];
    char telefone[100];
    char endereco[150];
    char cep[100];
    char local[100];
    char numero_casa[100];
    char bairro[100];
    char cidade[100];
    char estado[100];
    char senha_cliente[100];
    float saldo;
} Conta_poupanca1;

// Estrutura para Conta Corrente
typedef struct {
    char agencia[100];
    char numero_conta[100];
    char limite_conta[100];
    char data_vencimento[100];
    char nome_cliente[100];
    char cpf[100];
    char data_nascimento[100];
    char telefone[100];
    char endereco[150];
    char cep[100];
    char local[100];
    char numero_casa[100];
    char bairro[100];
    char cidade[100];
    char estado[100];
    char senha_cliente[100];
    float saldo;
} Conta_corrente1;

//Estrutura para o cadastro do funcionario
typedef struct {
	char codigo_funcionario[100];
	char cargo[100];
	char nome_funcionario[100];
	char cpf[100];
	char data_nascimento[100];
	char telefone[100];
	char endereco[100];
	char cep[100];
	char local[100];
	char numero_casa[100];
	char bairro[100];
	char cidade[100];
	char estado[100];
	char senha[100];
} Cadastro_funcionario2;

Conta_poupanca1 conta_poupanca1;
Conta_corrente1 conta_corrente1;
Cadastro_funcionario2 cadastro_funcionario2;


void cliente();
void admin();
void menu();
void menuf();
void abertura();
void conta_poupanca();
void conta_corrente();
void encerramento_conta();
void consultar_dados();
void consultar_conta();
void consultar_funcionario();
void consultar_cliente();
void alterar_dados();
void alterar_dados1();
void alterar_conta();
void alterar_conta1();
void alterar_funcionario();
void alterar_funcionario1();
void alterar_cliente();
void alterar_cliente1();
void cadastro_funcionario();
void cadastro_funcionario1();
void gerar_relatorio();
void gerar_relatorio1();
void gerar_nome();
void gerar_idade();

void menuc();
void saldo();
void deposito();
void saque();
void extrato();
void extrato1();
void limite();
int saldo_atual = 0;
int limite_disponivel = 1000;
int extrato_valor = 0;

int main(){
    menu(); 
    return 0;
}

void menu(){
    int op;
    system("cls");
    printf("                                              BEM VINDO AO BANCO MALVADER\n\n");
    printf("                                                    ============\n");
    printf("                                                    =---MENU---=\n");
    printf("                                                    ============\n");
    printf("--Escolha uma opcao--\n\n");
    printf("=========================\n");
    printf("= 1- Para cliente       =\n");
    printf("= 2- Para funcionario   =\n");
    printf("= 3- Sair               = \n");
    printf("=========================");
    scanf("%d", &op);
    switch(op){
        case 1: 
            cliente();
            break;
        case 2: 
            admin();
            break;
        case 3: 
            printf("Saindo...\n");
            break;
        default:
            printf("-- Opcao invalida! --\n");
            menu();
            break;
    }
}

void cliente() {
    char senha[20];
    system("cls");
    printf("=========================\n");
    printf("=Voce selecionou usuario=\n");
    printf("=========================\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, USER_PASSWORD) == 0){
        printf("--Acesso permitido--\n");
        system("cls");
        menuc();
    } else {
        printf("Acesso negado!\n");
        system("cls");
        menu();
    }
}

void admin() {
    char senha[20];
    system("cls");
    printf("Voce selecionou funcionario\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, ADMIN_PASSWORD) == 0){
        printf("Acesso permitido\n");
        system("cls");
        menuf();
    } else {
        printf("Acesso negado!\n");
        system("cls");
        menu();
    }
}

void menuc() {
    int op;
    printf("                                                    =================\n");
    printf("                                                    =MENU DO CLIENTE=\n");
    printf("                                                    =================\n\n");
    printf("Escolha uma opcao:\n\n");
    printf("-> 1 - Saldo\n");
    printf("-> 2 - Deposito\n");
    printf("-> 3 - Saque\n");
    printf("-> 4 - Extrato\n");
    printf("-> 5 - Consultar limite\n");
    printf("-> 6 - Sair\n");
    scanf("%d", &op);

    switch(op) {
        case 1: 
            saldo();
            break;
        case 2: 
            deposito();
            break;
        case 3: 
            saque();
            break;
        case 4: 
            extrato();
            break;
        case 5: 
            limite();
            break;
        case 6:
            menu();
            break;
        default:
            printf("Opcao invalida!\n");
            menuc();
            break;
    }
}

void saldo() {
    char senha[20];
    system("cls");
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    if(strcmp(senha, USER_PASSWORD) == 0) {
        printf("Saldo atual: %d\n", saldo_atual);
    } else {
        printf("Acesso negado!\n");
    }
    menuc();
}

void deposito() {
    int valor;
    system("cls");
    printf("Digite o valor a ser depositado: ");
    scanf("%d", &valor);
    saldo_atual += valor;
    printf("Valor registrado no banco: %d\n\n", valor);
    menuc();
}

void saque() {
    char senha[20];
    int valor;
    system("cls");
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    if(strcmp(senha, USER_PASSWORD) == 0) {
        printf("Informe o valor do saque: ");
        scanf("%d", &valor);
        saldo_atual -= valor;
        printf("O valor debitado foi: %d\n", valor);
        extrato_valor -= valor;
    } else {
        printf("Senha incorreta!\n\n");
        system("cls");
    }
    menuc();
}

void extrato() {
    char senha[20];
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, USER_PASSWORD) == 0){
        extrato1();
    } else {
        printf("Acesso negado!\n");
        system("cls");
        menuc();
    }
}

void extrato1(){
	FILE *file = fopen("extrato.csv", "w");

    if (file == NULL) {
    	system("cls");
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fprintf(file, "                                                    ===================\n");
    fprintf(file, "                                                    = Extrato Bancario=\n");
    fprintf(file, "                                                    ===================\n\n");
    fprintf(file, "Saldo atual,%d\n", saldo_atual);
    fprintf(file, "Extrato,%d\n", extrato_valor);
    fprintf(file, "Limite disponivel,%d\n", limite_disponivel);
    fprintf(file, "Limite indisponivel,%d\n", limite_disponivel - saldo_atual);
    fprintf(file, "---------------------------\n");

    fclose(file);
    system("cls");
    printf("Extrato gerado com sucesso em 'extrato.csv'!\n");
    menuc();
}

void limite() {
    char senha[20];
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    if(strcmp(senha, USER_PASSWORD) == 0) {
        printf("Limite disponivel: %d\n", limite_disponivel);
        printf("Limite indisponivel: %d\n", limite_disponivel - saldo_atual);
    } else {
        printf("Senha incorreta!\n\n");
        system("cls");
    }
    menuc();
}

void menuf(){
    int op;
    system("cls");
    printf("                                                   =====================\n");
    printf("                                                   =MENU DO FUNCIONARIO=\n");
    printf("                                                   =====================\n\n");
    printf("Escolha uma opcao:\n");
    printf("-> 1- Abertura de conta\n");
    printf("-> 2- Encerramento de conta\n");
    printf("-> 3- Consultar dados\n");
    printf("-> 4- Alterar dados\n");
    printf("-> 5- Cadastro de funcionarios\n");
    printf("-> 6- Gerar relatorios\n");
    printf("-> 7- Sair\n\n");
    scanf("%d", &op);
    switch(op){
        case 1: 
            abertura();
            break;
        case 2: 
            encerramento_conta();
            break;
        case 3: 
            consultar_dados();
            break;
        case 4:
            alterar_dados();
            break;
        case 5:
            cadastro_funcionario();
            break;
        case 6:
            gerar_relatorio();
            break;
        case 7:
            menu();
            break;
        default:
            printf("Opcao invalida!\n");
            menuf();
            break;
    }
}

void abertura() {
    int op;
    system("cls");
    do {
        printf("-> 1- Conta Poupanca\n");
        printf("-> 2- Conta Corrente\n");
        printf("-> 3- Voltar\n\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                conta_poupanca();
                break;
            case 2:
                conta_corrente();
                break;
            case 3:
                menuf();
                break;
            default:
                printf("Opcao invalida. Por favor, escolha novamente.\n");
                break;
        }
    } while (op != 3);
}

void conta_poupanca() {
	system("cls");
    printf("\nCadastro de Conta Poupanca\n");
    printf("-> 1- AGENCIA: ");
    scanf("%s",conta_poupanca1.agencia);
    printf("-> 2- NUMERO DA CONTA: ");
    scanf("%s",conta_poupanca1.numero_conta);
    printf("-> 3- NOME DO CLIENTE: ");
    scanf("%s",conta_poupanca1.nome_cliente);
    printf("-> 4- CPF DO CLIENTE: ");
    scanf("%s",conta_poupanca1.cpf);
    printf("-> 5- DATA DE NASCIMENTO: ");
    scanf("%s",conta_poupanca1.data_nascimento);
    printf("-> 6- TELEFONE DE CONTATO: ");
    scanf("%s",conta_poupanca1.telefone);
    printf("-> 7- ENDERECO DO CLIENTE: ");
    scanf("%s",conta_poupanca1.endereco);
    printf("-> 8- CEP: ");
    scanf("%s",conta_poupanca1.cep);
    printf("-> 9- LOCAL: ");
    scanf("%s",conta_poupanca1.local);
    printf("-> 10- NUMERO DA CASA: ");
    scanf("%s",conta_poupanca1.numero_casa);
    printf("-> 11- BAIRRO: ");
    scanf("%s",conta_poupanca1.bairro);
    printf("-> 12- CIDADE: ");
    scanf("%s",conta_poupanca1.cidade);
    printf("-> 13- ESTADO: ");
    scanf("%s",conta_poupanca1.estado);
    printf("-> 14- SENHA DO CLIENTE: ");
    scanf("%s",conta_poupanca1.senha_cliente);

    conta_poupanca1.saldo = 0.0;

    printf("\nConta Poupanca criada com sucesso!\n");
}

void conta_corrente() {
	system("cls");
    printf("\nCadastro de Conta Corrente\n");
    printf("-> 1- AGENCIA: ");
    scanf("%s", conta_corrente1.agencia);
    printf("-> 2- NUMERO DA CONTA: ");
    scanf("%s", conta_corrente1.numero_conta);
    printf("-> 3- LIMITE DA CONTA: ");
    scanf("%s", conta_corrente1.limite_conta);
    printf("-> 4- DATA DE VENCIMENTO: ");
    scanf("%s", conta_corrente1.data_vencimento);
    printf("-> 5- NOME DO CLIENTE: ");
    scanf("%s", conta_corrente1.nome_cliente);
    printf("-> 6- CPF DO CLIENTE: ");
    scanf("%s", conta_corrente1.cpf);
    printf("-> 7- DATA DE NASCIMENTO: ");
    scanf("%s", conta_corrente1.data_nascimento);
    printf("-> 8- TELEFONE DE CONTATO: ");
    scanf("%s", conta_corrente1.telefone);
    printf("-> 9- ENDERECO DO CLIENTE: ");
    scanf("%s", conta_corrente1.endereco);
    printf("-> 10- CEP: ");
    scanf("%s", conta_corrente1.cep);
    printf("-> 11- LOCAL: ");
    scanf("%s", conta_corrente1.local);
    printf("-> 12- NUMERO DA CASA: ");
    scanf("%s", conta_corrente1.numero_casa);
    printf("-> 13- BAIRRO: ");
    scanf("%s", conta_corrente1.bairro);
    printf("-> 14- CIDADE: ");
    scanf("%s", conta_corrente1.cidade);
    printf("-> 15- ESTADO: ");
    scanf("%s", conta_corrente1.estado);
    printf("-> 15- SENHA DO CLIENTE: ");
    scanf("%s", conta_corrente1.senha_cliente);

    conta_corrente1.saldo = 0.0;

    printf("\nConta Corrente criada com sucesso!\n");
}

void encerramento_conta() {
	char adm_password[100];
    char numero_de_conta[100];
    
    system("cls");
    printf("<<<<<ENCERRAMENTO DE CONTA>>>>>\n");
    printf("Digite sua senha de administrador para o encerramento: ");
    scanf("%s", adm_password);

    if (strcmp(adm_password, ADMIN_PASSWORD) == 0) {
        printf("Senha autorizada! \n");
        printf("Digite o numero da conta que sera encerrada: ");
        scanf("%s", numero_de_conta);
        printf("Conta %s encerrada com sucesso!\n", numero_de_conta);
        menuf();
    } else {
        printf("Acesso negado, tente novamente.\n");
     }
}

void consultar_dados() {
    int op;
    system("cls");
    do {
        printf("-> 1- Consultar conta\n");
        printf("-> 2- Consultar Funcionario\n");
        printf("-> 3- Consultar Cliente\n");
        printf("-> 4- Voltar\n\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                consultar_conta();
                break;
            case 2:
                consultar_funcionario();
                break;
            case 3:
                consultar_cliente();
                break;
            case 4:
                menuf();
                break;
            default:
                printf("Opcao invalida. Por favor, escolha novamente.\n");
                break;
        }
    } while (op != 4);
}

void consultar_conta() {
	system("cls");
    printf("                                                   ===================\n");
    printf("                                                   =\nConsultar Conta=\n");
    printf("                                                   ===================\n\n");
    printf("Tipo de conta: Corrente\n");
    printf("Nome do cliente: %s\n", conta_corrente1.nome_cliente);
    printf("CPF do cliente: %s\n", conta_corrente1.cpf);
    printf("Saldo da conta: R$%.2f\n", conta_corrente1.saldo);
    printf("Limite disponivel: %s\n", conta_corrente1.limite_conta);
    printf("Data de vencimento: %s\n", conta_corrente1.data_vencimento);
}

void consultar_funcionario() {
	system("cls");
    printf("                                                   =======================\n");
    printf("                                                   =Consultar Funcionario=\n");
    printf("                                                   =======================\n\n");
    printf("-> Codigo Funcionario: %s\n", cadastro_funcionario2.codigo_funcionario);
    printf("-> Cargo: %s\n", cadastro_funcionario2.cargo);
    printf("-> Nome do Funcionario: %s\n", cadastro_funcionario2.nome_funcionario);
    printf("-> CPF do Funcionario: %s\n", cadastro_funcionario2.cpf);
    printf("-> Data de Nascimento: %s\n", cadastro_funcionario2.data_nascimento);
    printf("-> Telefone: %s\n", cadastro_funcionario2.telefone);
    printf("-> Local: %s\n", cadastro_funcionario2.local);
    printf("-> Numero da Casa: %s\n", cadastro_funcionario2.numero_casa);
    printf("-> CEP: %s\n", cadastro_funcionario2.cep);
    printf("-> Bairro: %s\n", cadastro_funcionario2.bairro);
    printf("-> Cidade: %s\n", cadastro_funcionario2.cidade);
    printf("-> Estado: %s\n", cadastro_funcionario2.estado);
    menuf();
}

void consultar_cliente() {
	system("cls");
    printf("                                                   ===================\n");
    printf("                                                   =Consultar Cliente=\n");
    printf("                                                   ===================\n\n");
    printf("-> Nome do Cliente: %s\n", conta_poupanca1.nome_cliente);
    printf("-> CPF do Cliente: %s\n", conta_poupanca1.cpf);
    printf("-> Data de Nascimento: %s\n", conta_poupanca1.data_nascimento);
    printf("-> Telefone: %s\n", conta_poupanca1.telefone);
    printf("-> Local (Endereco): %s\n", conta_poupanca1.endereco);
    printf("-> Numero da Casa: %s\n", conta_poupanca1.numero_casa);
    printf("-> CEP: %s\n", conta_poupanca1.cep);
    printf("-> Bairro: %s\n", conta_poupanca1.bairro);
    printf("-> Cidade: %s\n", conta_poupanca1.cidade);
    printf("-> Estado: %s\n", conta_poupanca1.estado);
}
void alterar_dados() {
    int op;
    system("cls");
    do {
        printf("-> 1- Alterar conta\n");
        printf("-> 2- Alterar funcionario\n");
        printf("-> 3- Alterar cliente\n");
        printf("-> 4- Voltar\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                alterar_conta();
                break;
            case 2:
                alterar_funcionario();
                break;
            case 3:
                alterar_cliente();
                break;
            case 4:
                menuf();
                break;
            default:
                printf("Opcao invalida. Por favor, escolha novamente.\n");
                break;
        }
    } while (op != 4);
}

void alterar_conta() {
    char senha[20];
    system("cls");
    printf("                                                   <<<< Voce selecionou alterar conta >>>>\n\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, ADMIN_PASSWORD) == 0) {
        alterar_conta1();
    } else {
        printf("Acesso negado!\n");
        alterar_dados();
    }
}

void alterar_conta1() {
	int op;
	system("cls");
        printf("Escolha uma opcao:\n");
        printf("-> 1 - Alterar tipo de conta\n");
        printf("-> 2 - Alterar nome do cliente\n");
        printf("-> 3 - Alterar CPF do cliente\n");
        printf("-> 4 - Alterar saldo da conta\n");
        printf("-> 5 - Alterar limite disponivel\n");
        printf("-> 6 - Alterar data de vencimento\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Novo tipo de conta: ");
                scanf("%s", conta_corrente1.agencia);
                alterar_dados();
                break;
            case 2:
                printf("Novo nome do cliente: ");
                scanf("%s", conta_corrente1.nome_cliente);
                alterar_dados();
                break;
            case 3:
                printf("Novo CPF do cliente: ");
                scanf("%s", conta_corrente1.cpf);
                alterar_dados();
                break;
            case 4:
                printf("Novo saldo da conta: ");
                scanf("%f", &conta_corrente1.saldo);
                alterar_dados();
                break;
            case 5:
                printf("Novo limite disponivel: ");
                scanf("%f", &conta_corrente1.saldo);
                alterar_dados();
                break;
            case 6:
                printf("Nova data de vencimento: ");
                scanf("%s", conta_corrente1.data_nascimento);
                alterar_dados();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                alterar_conta1();
                break;
        }
}

void alterar_funcionario() {
    char senha[20];
    system("cls");
    printf("                                                   <<<< Voce selecionou alterar funcionario >>>>\n\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, ADMIN_PASSWORD) == 0) {
        alterar_funcionario1();
    } else {
        printf("Acesso negado!\n");
        alterar_dados();
    }
}

void alterar_funcionario1() {
	int op;
	system("cls");
    printf("-> 1- Codigo do funcionario \n");
    printf("-> 2- Cargo \n");
    printf("-> 3- Telefone \n");
    printf("-> 4- Local(Endereco) \n");
    printf("-> 5- Numero da casa \n");
    printf("-> 6- CEP \n");
    printf("-> 7- Bairro \n");
    printf("-> 8- Cidade \n");
    printf("-> 9- Estado \n");
    scanf("%d", &op);
		switch (op) {
			case 1:
                printf("Novo codigo do funcionario: ");
                scanf("%s", cadastro_funcionario2.codigo_funcionario);
                alterar_dados();
                break;
            case 2:
                printf("Novo Cargo: ");
                scanf("%s", cadastro_funcionario2.cargo);
                alterar_dados();
                break;
            case 3:
                printf("Novo Telefone: ");
                scanf("%s", cadastro_funcionario2.telefone);
                alterar_dados();
				break;
            case 4:
                printf("Novo Local: ");
                scanf("%s", cadastro_funcionario2.local);
                alterar_dados();
                break;
            case 5:
                printf("Novo numero da casa: ");
                scanf("%s", cadastro_funcionario2.numero_casa);
                break;
            case 6:
                printf("Novo CEP: ");
                scanf("%s", cadastro_funcionario2.cep);
                alterar_dados();
                break;
            case 7:
            	printf("Novo bairro: ");
            	scanf("%s", cadastro_funcionario2.bairro);
            	alterar_dados();
            	break;
            case 8:
            	printf("Nova cidade: ");
            	scanf("%s", cadastro_funcionario2.cidade);
            	alterar_dados();
            case 9:
            	printf("Nova Estado: ");
            	scanf("%s", cadastro_funcionario2.estado);
            	alterar_dados();
            default:
                printf("Opcao invalida! Tente novamente.\n");
                alterar_cliente1();
                break;
        }
    
}

void alterar_cliente() {
    char senha[20];
    system("cls");
    printf("                                                   <<<< Voce selecionou alterar cliente>>>>\n\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, ADMIN_PASSWORD) == 0) {
        alterar_cliente1();
    } else {
        printf("Acesso negado!\n");
        alterar_dados();
    }
}

void alterar_cliente1() {
    int op;
    	system("cls");
        printf("Escolha uma opcao:\n");
        printf("-> 1 - Alterar telefone\n");
        printf("-> 2 - Alterar nome do cliente\n");
        printf("-> 3 - Alterar CPF do cliente\n");
        printf("-> 4 - Alterar saldo da conta\n");
        printf("-> 5 - Alterar limite disponivel\n");
        printf("-> 6 - Alterar data de vencimento\n");
        scanf("%d", &op);
		switch (op) {
            case 1:
                printf("Novo telefone: ");
                scanf("%s", conta_corrente1.telefone);
                alterar_dados();
                break;
            case 2:
                printf("Novo local(endereco): ");
                scanf("%s", conta_corrente1.local);
                alterar_dados();
                break;
            case 3:
                printf("Novo numero da casa: ");
                scanf("%s", conta_corrente1.numero_casa);
                alterar_dados();
				break;
            case 4:
                printf("Novo CEP: ");
                scanf("%f", &conta_corrente1.cep);
                alterar_dados();
                break;
            case 5:
                printf("Novo bairro: ");
                scanf("%f", &conta_corrente1.bairro);
                break;
            case 6:
                printf("Nova cidade: ");
                scanf("%s", conta_corrente1.cidade);
                alterar_dados();
                break;
            case 7:
            	printf("Novo estado: ");
            	scanf("%s", conta_corrente1.estado);
            	alterar_dados();
            	break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                alterar_cliente1();
                break;
        }
}

void cadastro_funcionario() {
    char senha[20];
    system("cls");
    printf("<< Digite a senha do Administrador >>\n\n");
    printf("Insira a senha: ");
    scanf("%s", senha);
    if(strcmp(senha, ADMIN_PASSWORD) == 0) {
        cadastro_funcionario1();
    } else {
        printf("Acesso negado!\n");
        menuf();
    }
}

void cadastro_funcionario1() {
	system("cls");
	printf("-> 1- Codigo funcionario: ");
	scanf("%s", cadastro_funcionario2.codigo_funcionario);
	printf("-> 2- Cargo: ");
	scanf("%s", cadastro_funcionario2.cargo);
	printf("-> 3- Nome do funcionario: ");
	scanf("%s", cadastro_funcionario2.nome_funcionario);
	printf("-> 4- CPF do funcionario: ");
	scanf("%s", cadastro_funcionario2.cpf);
	printf("-> 5- Data de nascimento: ");
	scanf("%s", cadastro_funcionario2.data_nascimento);
	printf("-> 6- Telefone de contato: ");
	scanf("%s", cadastro_funcionario2.telefone);
	printf("-> 7- CEP: ");
	scanf("%s", cadastro_funcionario2.cep);
	printf("-> 8- Local: ");
	scanf("%s", cadastro_funcionario2.local);
	printf("-> 9- Numero da casa: ");
	scanf("%s", cadastro_funcionario2.numero_casa);
	printf("-> 10- Bairro: ");
	scanf("%s", cadastro_funcionario2.bairro);
	printf("-> 11- Cidade: ");
	scanf("%s", cadastro_funcionario2.cidade);
	printf("-> 12- Estado: ");
	scanf("%s", cadastro_funcionario2.estado);
	printf("-> 13- Senha do funcionario: ");
	scanf("%s", cadastro_funcionario2.senha);
	
	printf("\nConta cadastrada com sucesso!\n");
	menuf();
}

void gerar_relatorio() {
    char senha[50];
    system("cls");
    printf("Digite a senha do funcionario: ");
    scanf("%s", senha);
    if(strcmp(senha, USER_PASSWORD) == 0){
        gerar_relatorio1();
    } else {
        printf("Senha incorreta\n");
        menuf();
    }
}

void gerar_relatorio1() {
	FILE *file = fopen("relatorio.csv", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    fprintf(file, "----- Relatorio de Contas Poupanca -----\n");
    fprintf(file, "Agencia,Numero da Conta,Nome do Cliente,CPF,Data de Nascimento,Telefone,Endereco,CEP,Local,Numero da Casa,Bairro,Cidade,Estado,Saldo\n");
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%.2f\n",
            conta_poupanca1.agencia, conta_poupanca1.numero_conta, conta_poupanca1.nome_cliente, conta_poupanca1.cpf, conta_poupanca1.data_nascimento, conta_poupanca1.telefone,
            conta_poupanca1.endereco, conta_poupanca1.cep, conta_poupanca1.local, conta_poupanca1.numero_casa, conta_poupanca1.bairro, conta_poupanca1.cidade, conta_poupanca1.estado, conta_poupanca1.saldo);

    fprintf(file, "\n----- Relatorio de Contas Correntes -----\n");
    fprintf(file, "Agencia,Numero da Conta,Limite da Conta,Data de Vencimento,Nome do Cliente,CPF,Data de Nascimento,Telefone,Endereco,CEP,Local,Numero da Casa,Bairro,Cidade,Estado,Saldo\n");
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%.2f\n",
            conta_corrente1.agencia, conta_corrente1.numero_conta, conta_corrente1.limite_conta, conta_corrente1.data_vencimento, conta_corrente1.nome_cliente, conta_corrente1.cpf, conta_corrente1.data_nascimento,
            conta_corrente1.telefone, conta_corrente1.endereco, conta_corrente1.cep, conta_corrente1.local, conta_corrente1.numero_casa, conta_corrente1.bairro, conta_corrente1.cidade, conta_corrente1.estado, conta_corrente1.saldo);

    fprintf(file, "\n----- Relatorio de Funcionarios -----\n");
    fprintf(file, "Codigo do Funcionario,Cargo,Nome,CPF,Data de Nascimento,Telefone,Endereco,CEP,Local,Numero da Casa,Bairro,Cidade,Estado\n");
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            cadastro_funcionario2.codigo_funcionario, cadastro_funcionario2.cargo, cadastro_funcionario2.nome_funcionario, cadastro_funcionario2.cpf, cadastro_funcionario2.data_nascimento,
            cadastro_funcionario2.telefone, cadastro_funcionario2.endereco, cadastro_funcionario2.cep, cadastro_funcionario2.local, cadastro_funcionario2.numero_casa, cadastro_funcionario2.bairro,
            cadastro_funcionario2.cidade, cadastro_funcionario2.estado);

    fclose(file);
    printf("Relatorio gerado com sucesso em 'relatorio.csv'!\n");
    system("relatorio.csv");
    menuf();
}
