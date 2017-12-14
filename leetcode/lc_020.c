//
// LeetCode
// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/
//


/*
 * Stack ADT for character
 */
typedef struct stack_node {
    char value;
    struct stack_node *next;
} snode_t;

void stack_push(snode_t **s, char c) {
    snode_t *node;
    
    if ((node = (snode_t *) malloc(sizeof(snode_t))) == NULL)
        exit(EXIT_FAILURE);
    
    node->value = c;
    node->next = *s;
    *s = node;
}

bool stack_empty(snode_t *s) {
    return s == NULL;
}

char stack_pop(snode_t **s) {
    snode_t *old;
    char c;
    
    if (stack_empty(*s))
        return '\0';
    
    old = *s;
    c = old->value;
    *s = (*s)->next;
    free(old);
    
    return c;
}

char stack_peek(snode_t *s) {
    if (stack_empty(s))
        return '\0';

    return s->value;
}


/*
 * Check valid parentheses
 */
bool isValid(char* s) {
    int i;
    char c;
    snode_t *stack = NULL;
    
    for(i = 0; s[i] != '\0'; i++) {
        c = s[i];
        
        if (c == '(' || c == '[' || c == '{')
            stack_push(&stack, c);
        else if (c == ')' && !stack_empty(stack) && stack_peek(stack) == '(')
            stack_pop(&stack);
        else if (c == ']' && !stack_empty(stack) && stack_peek(stack) == '[')
            stack_pop(&stack);
        else if (c == '}' && !stack_empty(stack) && stack_peek(stack) == '{')
            stack_pop(&stack);
        else
            return false;
    }
    
    return stack_empty(stack);
}
