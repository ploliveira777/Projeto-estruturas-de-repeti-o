[README (2).md](https://github.com/user-attachments/files/32560956/README.2.md)
# Desafio de Monitoramento de Temperatura

## 1. Identificação

- **Aluno:** Paulo Victor Oliveira dos Santos
- **Disciplina:** Linguagem de Programação em C
- **Professora:** Profa. Karla Sartin
- **Título do projeto:** Sistema de Monitoramento de Temperatura

## 2. Objetivo

O objetivo do programa é realizar o monitoramento de temperaturas informadas pelo usuário, comparando cada leitura com um limite definido no início da execução. O sistema identifica situações acima do limite, controla a ocorrência de temperaturas elevadas consecutivas e encerra automaticamente o monitoramento quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório com a quantidade de leituras válidas, média, maior temperatura, menor temperatura, quantidade de temperaturas acima do limite e percentual de leituras acima do limite.

## 3. Funcionamento do programa

### Definição do limite

Primeiramente, o usuário informa o limite de temperatura. O programa utiliza um `do...while` para garantir que o limite seja solicitado pelo menos uma vez e seja repetido enquanto estiver inválido.

Para este projeto, foram considerados válidos valores de **-50 °C a 100 °C**.

### Realização das leituras

Depois de definir o limite, o programa entra no monitoramento e solicita as temperaturas continuamente.

Cada leitura pode ser:

- um valor válido entre -50 °C e 100 °C;
- uma entrada inválida, que é rejeitada e solicitada novamente;
- `-999`, utilizado como opção de encerramento manual.

### Tratamento de valores inválidos

Quando o usuário informa texto ou outro conteúdo que não pode ser interpretado como número, o programa identifica a falha de leitura, limpa o restante da entrada e solicita um novo valor.

Valores numéricos fora do intervalo de -50 °C a 100 °C também são considerados inválidos e não entram nos cálculos do relatório.

### Identificação de temperaturas acima do limite

Uma temperatura é considerada acima do limite quando:

```text
temperatura > limite
```

Quando isso acontece, o programa exibe uma mensagem de alerta e incrementa a quantidade de temperaturas acima do limite.

### Contagem de temperaturas consecutivas

O programa possui um contador chamado `consecutivas`.

- Se a temperatura estiver acima do limite, o contador é incrementado.
- Se a temperatura estiver dentro ou igual ao limite, o contador é zerado.
- Quando o contador chega a **3**, o monitoramento é encerrado automaticamente.

Dessa forma, temperaturas acima do limite que não forem consecutivas não provocam o encerramento.

### Condição de encerramento

O monitoramento termina em uma das seguintes situações:

1. três temperaturas consecutivas acima do limite;
2. entrada manual do valor `-999`.

Depois do encerramento, o programa apresenta o relatório final das leituras válidas.

## 4. Estruturas de repetição utilizadas

### `do...while`

O `do...while` é utilizado na definição do limite de temperatura:

```c
do {
    /* leitura e validação do limite */
} while (limite < TEMP_MIN || limite > TEMP_MAX);
```

A escolha é adequada porque o usuário precisa informar o limite pelo menos uma vez. A condição é verificada depois da primeira execução, permitindo repetir a solicitação somente quando o valor for inválido.

### `while`

O `while` é utilizado para o monitoramento das temperaturas:

```c
while (1) {
    /* leitura e processamento das temperaturas */
}
```

Nesse trecho, as leituras acontecem continuamente e o programa utiliza `break` para encerrar o laço quando ocorre uma das condições de parada.

A combinação das duas estruturas deixa cada parte do algoritmo coerente com sua finalidade: o `do...while` valida uma entrada obrigatória e o `while` controla o processo contínuo de monitoramento.

## 5. Como executar

É necessário ter um compilador C, como o GCC.

### Compilar

```bash
gcc monitoramento.c -o monitoramento
```

### Executar no Linux/macOS

```bash
./monitoramento
```

### Executar no Windows

```bash
monitoramento.exe
```

## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

**Objetivo:** verificar se o programa rejeita limite, texto e temperaturas fora do intervalo permitido.

Exemplo de entradas:

```text
Limite: 150
Limite: 30
Temperatura: abc
Temperatura: 120
Temperatura: 25
-999
```

**Resultado esperado/obtido:** o limite `150` foi rejeitado, a entrada textual `abc` foi rejeitada e a temperatura `120` foi rejeitada. A temperatura válida `25` foi registrada normalmente.

Evidência: `evidencias/teste01.png`

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

**Objetivo:** verificar se o contador de consecutivas é reiniciado quando aparece uma temperatura dentro do limite.

Exemplo de entradas:

```text
Limite: 30
Temperatura: 35
Temperatura: 25
Temperatura: 40
Temperatura: 20
Temperatura: 31
-999
```

**Resultado esperado/obtido:** as temperaturas `35`, `40` e `31` ficaram acima do limite, mas não foram consecutivas. O contador foi reiniciado pelas temperaturas `25` e `20`, portanto o monitoramento não foi encerrado automaticamente.

Evidência: `evidencias/teste02.png`

### Teste 3 — Três temperaturas consecutivas acima do limite

**Objetivo:** verificar o encerramento automático.

Exemplo de entradas:

```text
Limite: 30
Temperatura: 25
Temperatura: 35
Temperatura: 40
Temperatura: 31
```

**Resultado esperado/obtido:** após `35`, `40` e `31`, o contador chegou a três temperaturas consecutivas acima do limite. O programa exibiu o alerta e encerrou o monitoramento automaticamente, apresentando o relatório final.

Evidência: `evidencias/teste03.png`

## 7. Reflexão final

**Por que você escolheu `while`, `do...while` ou uma combinação das duas estruturas? Em qual parte do algoritmo a diferença entre testar a condição antes ou depois da execução foi importante para sua solução?**

Foi escolhida uma combinação de `do...while` e `while` porque cada estrutura se encaixa melhor em uma parte do algoritmo. O `do...while` foi usado para definir e validar o limite de temperatura, pois essa entrada precisa ser solicitada pelo menos uma vez antes que a condição de validade seja verificada. Já o `while` foi utilizado no monitoramento, pois as leituras precisam continuar acontecendo até que uma condição de encerramento seja alcançada. Assim, a diferença entre testar a condição depois ou manter a repetição contínua foi importante para organizar corretamente a validação inicial e o acompanhamento das temperaturas.

---

**Projeto individual — Profa. Karla Sartin**
