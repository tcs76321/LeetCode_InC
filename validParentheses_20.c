bool isValid(char * s){
    int opbIndex;
//    char orderPriorityBracket[5001] = {[0 ... 4999] = 'x'};
    char orderPriorityBracket[9000];
    for(opbIndex = 0; opbIndex < 5000 ;opbIndex++){
        orderPriorityBracket[opbIndex] = 'x';
    }
    orderPriorityBracket[5000] = '\0';

    int softBrackets = 0;
    int pointBrackets = 0;
    int hardBrackets = 0;

    char *i = s;
    while(*i != '\0'){
        if(*i == '('){
            softBrackets++;
            opbIndex++;
            orderPriorityBracket[opbIndex] = 's';
        }
        else if(*i == '{'){
            pointBrackets++;
            opbIndex++;
            orderPriorityBracket[opbIndex] = 'p';
        }
        else if(*i == '['){
            hardBrackets++;
            opbIndex++;
            orderPriorityBracket[opbIndex] = 'h';
        }
        else if(*i == ')'){
            if(opbIndex == -1){
                return false;
            }

            if(orderPriorityBracket[opbIndex] != 's'){
                return false;
            }
            orderPriorityBracket[opbIndex] = 'x';
            opbIndex--;

            softBrackets--;
            if(softBrackets < 0){
                return false;
            }
        }
        else if(*i == '}'){
            if(opbIndex == -1){
                return false;
            }

            if(orderPriorityBracket[opbIndex] != 'p'){
                return false;
            }
            orderPriorityBracket[opbIndex] = 'x';
            opbIndex--;

            pointBrackets--;
            if(pointBrackets < 0){
                return false;
            }
        }
        else if(*i == ']'){
            if(opbIndex == -1){
                return false;
            }

            if(orderPriorityBracket[opbIndex] != 'h'){
                return false;
            }
            orderPriorityBracket[opbIndex] = 'x';
            opbIndex--;

            hardBrackets--;
            if(hardBrackets < 0){
                return false;
            }
        }

        i++;
    }

    if(softBrackets == 0 && pointBrackets == 0 && hardBrackets == 0){
        return true;
    }
    return false;
}
