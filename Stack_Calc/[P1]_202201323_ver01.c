#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char element;

typedef struct StackNode
{
    element *data;
    struct StackNode *link;
} StackNode;

typedef struct
{
    struct StackNode *top;
} LinkedStackType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_stack(LinkedStackType *s)
{
    s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

void push(LinkedStackType *s, element *data)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = (element *)malloc(sizeof(strlen(data) + 1));
    strcpy(temp->data, data);
    temp->link = s->top;
    s->top = temp;
}

element *pop(LinkedStackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택공백에러");
        exit(1);
    }
    else
    {
        StackNode *temp = s->top;
        element *result = strdup(temp->data);
        s->top = temp->link; // s->top->link;
        free(temp->data);
        free(temp);

        return result;
    }
}

element peek(LinkedStackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else
    {
        return s->top->data[0];
    }
}

int check_matching(element *in) // 괄호 검사 함수
{
    LinkedStackType s;
    init_stack(&s);

    char ch;
    char str[2];
    int n = strlen(in);

    for (int i = 0; i < n; i++)
    {
        ch = in[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            str[0] = ch;
            str[1] = '\0';
            push(&s, str);
            break;
        case ')':
        case ']':
        case '}':
            if (is_empty(&s))
            {
                error("괄호 조건 위반\n");
            }
            else
            {
                element *open_ch = pop(&s);
                if ((open_ch[0] == '(' && ch != ')') || (open_ch[0] == '{' && ch != '}') || (open_ch[0] == '{' && ch != '}'))
                {
                    error("괄호 조건 위반\n");
                }
                break;
            }
        }
    }
    if (!is_empty(&s))
    {
        error("괄호 조건 위반\n");
    }
    else
    {
        return 1;
    }
}

int check_exp(element *exp) // 식 검사 함수
{

    int hasDigit = -1; // 숫자가 하나라도 있는지 확인하기 위한 변수

    int n = strlen(exp);

    // 수식에서 첫 문자가 숫자 또는 괄호가 아니라면 오류 처리
    if ((!isdigit(exp[0]) && (exp[0] != '(') && (exp[0] != '[') && (exp[0] != '{')))
    {
        error("수식에러");
    }

    for (int i = 0; i < n; i++)
    {
        char lastchar, current = exp[i];

        // 문자가 유효한지 검사 (잘못된 문자가 포함되어있는지 확인)
        if (!isdigit(current) && current != '+' && current != '-' && current != '*' && current != '/' && current != ')' && current != ']' && current != '}' && current != '(' && current != '{' && current != '['&& current != '.')
        {
            printf("잘못된 문자 '%c'가 포함되어 있습니다.\n", current);
            error("수식에러");
        }

        if (isdigit(current))
        {
            hasDigit = 1;
        }

        // 연속된 연산자와 연속된 괄호 검사
        if ((current == '+' || current == '-' || current == '*' || current == '/' || current == ')' || current == ']' || current == '}') &&
            (lastchar == '+' || lastchar == '-' || lastchar == '*' || lastchar == '/' || lastchar == '(' || lastchar == '{' || lastchar == '['))
        {
            printf("연속된 연산자 '%c %c'가 있습니다.\n", lastchar, current);
            error("수식에러");
        }

        // 현재 문자가 공백이 아닐 경우에만 lastchar을 업데이트
        if (!isspace(current))
        {
            lastchar = current;
        }
    }
    // 숫자가 없는 경우 검사
    if (!hasDigit)
    {
        printf("수식에 숫자가 포함되어 있지 않습니다.\n");
        error("수식에러");
    }

    return 1;
}

int prec(char op)
{
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
element *infix_to_postfix(element *infix)
{
    LinkedStackType s;
    init_stack(&s);

    char ch;
    char str[100];
    int len = strlen(infix);
    int j = 0;
    element *output = (element *)malloc(sizeof(element) * (len * 2 + 1));

    for (int i = 0; i < len; i++)
    {
        ch = infix[i];

        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/': // 현재 문자가 연산자인 경우
            // 스택이 비어있지 않고, 스택의 top에 있는 연산자의 우선순위가 현재 연산자보다 크거나 같은 동안 반복
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
            {
                element *temp_str = pop(&s);  // 스택에서 연산자를 팝
                strcpy(&output[j], temp_str);  // 출력 문자열에 연산자를 추가
                j += strlen(temp_str);  // 인덱스 업데이트
                free(temp_str);  // 임시 문자열 메모리 해제
            }
            str[0] = ch;
            str[1] = ' ';
            str[2] = '\0';
            push(&s, str); // 현재 연산자를 스택에 푸시 
            break;
        case '(':
            str[0] = ch;
            str[1] = ' ';
            str[2] = '\0';
            push(&s, str); // 괄호를 스택에 푸시
            break;

        case ')':
            element *top_op = pop(&s);
            while (top_op[0] != '(')
            {
                output[j++] = top_op[0];
                output[j++] = ' ';
                free(top_op); // 메모리 해제
                top_op = pop(&s);
            }
            free(top_op); // 왼쪽 괄호 메모리 해제
            break;
        default: // 숫자나 피연산자 처리
            if (ch == '.') // 소수점 처리
            {
                output[--j] = ch; // 소수점 추가
                j++;
                i++;
                while (isdigit(infix[i]))
                {
                    output[j++] = infix[i];
                    i++;
                }
                output[j++] = ' ';
                i--;
            }
            else
            {
                output[j++] = ch;
                output[j++] = ' ';
                break;
            }
        }
    }
     // 스택이 비어있지 않은 동안 모든 연산자를 팝하고 출력 문자열에 추가
    while (!is_empty(&s))
    {
        element *temp_str = pop(&s);
        strcpy(&output[j], temp_str);
        j = j + strlen(temp_str);
        free(temp_str);
    }
    output[j] = '\0';  // 문자열의 끝을 나타내는 NULL 문자 추가

    return output;  // 변환된 후위 표기법 수식 반환
}

double postfix_eval(element *postfix) // 후위 표기 수식 계산
{
    double op1, op2, value;
    int len = strlen(postfix);

    char str[10];
    char num[100]; // 임시 버퍼로 숫자를 문자열로 처리

    LinkedStackType s;
    init_stack(&s);
    for (int i = 0; i < len; i++)
    {
        int j = 0;
        while (postfix[i] != ' ')
        {
            str[j] = postfix[i++];
            j++;
        }
        str[j] = '\0';
        //printf("%s\n", str);
        if (str[0] != '+' && str[0] != '-' && str[0] != '*' && str[0] != '/' && str[0] != ' ')
        {
            push(&s, str); // 피연산자를 문자열로 스택에 저장
        }
        else if (str[0] != ' ')
        {
            char *op2_str = pop(&s);
            char *op1_str = pop(&s);
            op2 = atof(op2_str); // 실수 자료형으로 변환
            op1 = atof(op1_str);
            switch (str[0])
            {
            case '+':
                snprintf(num, sizeof(num), "%lf", op1 + op2); 
                break;
            case '-':
                snprintf(num, sizeof(num), "%lf", op1 - op2);
                break;
            case '*':
                snprintf(num, sizeof(num), "%lf", op1 * op2);
                break;
            case '/':
                snprintf(num, sizeof(num), "%lf", op1 / op2);
                break;
            }
            push(&s, num);
        }
    }
    char *result_str = pop(&s);
    double result = atof(result_str); // 실수 자료형으로 변환
    return result;
}

// 후위 표기 수식 -> 전위 표기 수식
element *postfix_to_prefix(element *postfix)
{
    LinkedStackType s;
    init_stack(&s);

    int len = strlen(postfix);
    char ch;
    char str[10];
    char temp[100];
    element *prefix = (element *)malloc(sizeof(element) * (len * 2 + 1)); // 반환 수식

    for (int i = 0; i < len; i++)
    {
        int j = 0;
        while (postfix[i] != ' ')
        {
            str[j] = postfix[i++];
            j++;
        }
        str[j] = '\0';

        if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/')
        {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            sprintf(temp, "%c %s %s", str[0], op2, op1); // 연산자를 앞에 두고 피연산자들을 뒤에 배치
            push(&s, temp);
        }
        else if (!(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ' ')) // 피연산자인 경우
        {

            push(&s, str);
        }
    }
    char *result = pop(&s);
    return result;
}

int main(void)
{

    element *input = malloc(100 * sizeof(element)); // 입력을 위한 메모리 할당
    element *postfix;
    element *prefix;

    printf("중위식을 입력하세요: ");
    scanf("%s", input);

    check_matching(input);
    check_exp(input);

    postfix = infix_to_postfix(input);   // 변환 함수 호출
    prefix = postfix_to_prefix(postfix); // 변환 함수 호출

    printf("전위식: %s\n", prefix);
    printf("후위식: %s\n", postfix);
    printf("계산결과: %lf\n", postfix_eval(postfix));

    free(input);
    free(postfix);
    free(prefix);

    return 0;
}