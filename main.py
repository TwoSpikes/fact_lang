from sys import *
from typing import TypeVar, Sequence
from enum import Enum, auto

T: TypeVar = TypeVar('T')
def myfilter(x: list[T], filt):
    res: list[T] = []
    for ip in range(len(x)):
        op = x[ip]
        if filt(op):
            res.append(op)
    return res

T: TypeVar = TypeVar('T')
def for_every_el(x: list[T], filt) -> list[T]:
    res: list[T] = []
    for ip in range(len(x)):
        op = x[ip]
        res.append(filt(op))
    return res

T: TypeVar = TypeVar('T')
def my_list_eq(a: list[T], b: T) -> bool:
    for ip in range(len(a)):
        op = a[ip]
        if op == b:
            return True
    return False

T: TypeVar = TypeVar('T')
def my_list_list_eq(a: list[T], b: T) -> bool:
    for ip in range(len(a)):
        op = a[ip]
        for ij in range(len(op)):
            oj = op[ij]
            if oj == b:
                return True
    return False

def str_range(a: str, b: str) -> list[str]:
    return for_every_el(range(ord(a), ord(b) + 1), lambda x: chr(x))

T: TypeVar = TypeVar('T')
def my_range(_min: T, _max: T, step: int = 1) -> list[T]:
    assert type(_min) == type(_max), f'different types: {type(_min)} and {type(_max)}'
    if type(_min) == int:
        return range(_min, _max)
    if my_list_eq([chr, str], type(_min)):
        return str_range(_min, _max)
    assert False, f'unknown type: {type(_min)}'

def is_symbol(x: chr) -> bool:
    return my_list_list_eq([
        str_range('a', 'z'),
        str_range('A', 'Z'),
        str_range('0', '9'),
    ], x) or my_list_eq([
        '_',
    ], x)


def my_split(operand: str) -> list[str]:
    # '>> .\nlll-_=838'
    # ['>>', '.\\', 'nll', '-', '_', '=', '838']
    # 'a b c_-'
    # ['a', 'b', 'c_', '-']
    res: list[str] = list[str]()
    tmp: bool = False
    for ip in range(len(operand)):
        op = operand[ip]
        if op == ' ':
            res.append(str())
        elif is_symbol(op) == tmp and ip > 0:
            res[-1] += op
        else:
            tmp = is_symbol(op)
            res.append(str())
            res[-1] = op
    return res


class Command:
    pass

class Plus(Command):
    operand: int = 0
    def __init__(_operand: int):
        operand = _operand

class Minus(Command):
    operand: int = 0
    def __init__(_operand: int):
        operand = _operand

class Next(Command):
    pass

class Prev(Command):
    pass

class Print(Command):
    pass

class Ins(Command):
    operand: int = 0
    def __init__(self, _operand: int):
        self.operand = _operand

class Null(Command):
    pass

Program: type = list[Command]

def interpret_program(x: Program):
    print(f'------ interpreting {len(x)} commands... ------')
    stack: list[int] = [0]
    stack_ptr: int = 0
    for ip in range(len(x)):
        op = x[ip]

        print(f'{ip}.', end=' ')
        if   isinstance(op, Plus):
            assert False, '`Plus` op is not implemented yet'
        elif isinstance(op, Minus):
            assert False, '`Minus` op is not implemented yet'
        elif isinstance(op, Next):
            print(f'---- next after={stack_ptr + 1} ----')
            stack_ptr += 1
            if stack_ptr > len(stack) - 1:
                stack.append(0)
        elif isinstance(op, Prev):
            print(f'---- prev after={stack_ptr - 1} ----')
            if stack_ptr <= 0:
                print(f'stack underflow: {stack_ptr - 1}')
                exit(1)
            stack_ptr -= 1
        elif isinstance(op, Print):
            print(f'---- print {stack_ptr} ----')
            print( stack[stack_ptr] )
        elif isinstance(op, Ins):
            print(f'---- insert oper={op.operand} ind={stack_ptr} ----')
            stack[stack_ptr] = op.operand
        else:
            assert False, f'interpret_program: unreachable_op: {op}'

class ParsingCommand(Enum):
    PLUS = auto(),
    MINUS = auto(),
    PRINT = auto(),
    NEXT = auto(),
    PREV = auto(),
    INS = auto(),
    NULL = auto(),

def parsing_warning(msg: str = 'Unknown', line_num: int = -1):
    print(f'parsing (line {line_num}): WARNING: {msg}')

def parsing_error(msg: str = 'Unknown', line_num: int = -1):
    print(f'parsing (line {line_num}): ERROR: {msg}')
    exit(1)

def main():
    lines: list[str] = []
    #read lines
    while True:
        lines.append(input('>>> '))
        if lines[-1] == 'FILEEND':
            lines.pop()
            break
    print(f'--------------------')

    #join lines
    lines_str: str = ' __NEW_LINE__ '.join(lines)
    print(f'lines_str={repr(lines_str)}')
    print(f'splitted={my_split(lines_str)}')

    #parsing
    splinp: str = my_split(lines_str)
    print(f'------ parsing {len(splinp)} words... ------')
    command: ParsingCommand = ParsingCommand.NULL
    program: Program = []
    line_num: int = 1
    for ip in range(len(splinp)):
        op = splinp[ip]
        match command:
            case ParsingCommand.NULL:
                match op:
                    case '+':
                        command = ParsingCommand.PLUS
                    case '-':
                        command = ParsingCommand.MINUS
                    case 'next':
                        program.append(Next())
                    case 'prev':
                        program.append(Prev())
                    case 'print':
                        program.append(Print())
                    case 'ins':
                        command = ParsingCommand.INS
                    case '__NEW_LINE__':
                        line_num += 1
                    case '':
                        parsing_warning('Mysplit splitted operations and left extra empty string', line_num)
                    case ' ':
                        parsing_warning('Mysplit splitted operations and left extra space string', line_num)
                    case _:
                        parsing_error(f'Unknown command: {op}', line_num)
            case ParsingCommand.PLUS:
                command = ParsingCommand.NULL
                program.append(Plus(int(op)))
            case ParsingCommand.MINUS:
                command = ParsingCommand.NULL
                program.append(Minus(int(op)))
            case ParsingCommand.INS:
                command = ParsingCommand.NULL
                program.append(Ins(int(op)))
            case _:
                assert False, f'parsing (line {line_num}): unknown `command`: {command}'
    interpret_program(program)

def test():
    print(my_split('>> .\nlll-_=838'))

if __name__ == '__main__':
    main()
