#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

static bool isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

static bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (true);
    return (false);
}

static void validateExpr(std::string expr)
{
    for (unsigned long i = 0; i < expr.length(); i++)
    {
        if (i % 2 != 0 && expr[i] == ' ')
            continue;
        else if (i % 2 == 0 && (isdigit(expr[i]) || isOperator(expr[i])))
            continue;
        else
            throw RPN::Error();
    }
}

static bool performOperation(std::stack<int> &stack, const std::string &op)
{
    if (stack.size() < 2)
    {
        std::cout << "Error: Not enough operands for operator " << op << std::endl;
        return false;
    }

    int operand2 = stack.top();
    stack.pop();
    int operand1 = stack.top();
    stack.pop();

    if (op == "+")
        stack.push(operand1 + operand2);
    else if (op == "-")
        stack.push(operand1 - operand2);
    else if (op == "*")
        stack.push(operand1 * operand2);
    else if (op == "/")
    {
        if (operand2 == 0)
        {
            std::cout << "Error: Division by zero" << std::endl;
            return false;
        }
        stack.push(operand1 / operand2);
    }

    return true;
}

void RPN::evaluate(std::string s)
{
    std::stringstream ss(s);
    std::string token;
    int res = 0;

    try
    {
        validateExpr(s);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    while (ss >> token)
    {
        if (isOperator(token))
        {
            if (!performOperation(_stack, token))
                res = INT_MIN;
        }
        else
            _stack.push(stoi(token));
    }
    if (_stack.size() != 1)
    {
        std::cout << "Error: Invalid expression" << std::endl;
    }
    res = _stack.top();
    if (res != INT_MIN)
        std::cout << _stack.top() << std::endl;
}