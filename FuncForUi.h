#pragma once
#include <iostream>
int getStatus(std::string& comand)
{
    if (comand == "Run tests for vector")
    {
        return 0;
    }
    else if (comand == "Run tests for stack")
    {
        return 1;
    }
    else if (comand == "Run tests for queue")
    {
        return 2;
    }
    else if (comand == "Use int vector for sum")
    {
        return 3;
    }
    else if (comand == "Use int vector for multi" )
    {
        return 4;
    }
    else if (comand == "Use int vector for multionscalar" )
    {
        return 5;
    }
    else if (comand == "Use complex vector for sum" )
    {
        return 6;
    }
    else if (comand == "Use complex vector for multi" )
    {
        return 7;
    }
    else if (comand == "Use int stack for concat" )
    {
        return 8;
    }
    else if (comand == "Use int stack for substack" )
    {
        return 9;
    }
    else if (comand == "Use int stack for issubsequencehere" )
    {
        return 10;
    }
    else if (comand == "Use complex stack for concat" )
    {
        return 11;
    }
    else if (comand == "Use complex stack for substack" )
    {
        return 12;
    }
    else if (comand == "Use complex stack for issubsequencehere" )
    {
        return 13;
    }
    else if (comand == "Use person stack for concat" )
    {
        return 14;
    }
    else if (comand == "Use person stack for substack" )
    {
        return 15;
    }
    else if (comand == "Use person stack for issubsequencehere" )
    {
        return 16;
    }
    else if (comand == "Use int queue for concat" )
    {
        return 17;
    }
    else if (comand == "Use int queue for subqueue" )
    {
        return 18;
    }
    else if (comand == "Use int queue for issubsequencehere" )
    {
        return 19;
    }
    else if (comand == "Use complex queue for concat" )
    {
        return 20;
    }
    else if (comand == "Use complex queue for subqueue" )
    {
        return 21;
    }
    else if (comand == "Use complex queue for issubsequencehere" )
    {
        return 22;
    }
    else if (comand == "Use person queue for concat" )
    {
        return 23;
    }
    else if (comand == "Use person vector for sum" )
    {
        return 24;
    }
    else if (comand == "Use person queue for subqueue" )
    {
        return 25;
    }
    else if (comand == "Stop" )
    {
        return 26;
    }
    else
    {
        return 27;
    }
}
