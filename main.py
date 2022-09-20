
import sys
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

def is_symbol_space(x: chr) -> bool:
    return is_symbol(x) or x == ' '


def my_split(operand: str) -> list[str]:
    # >> .\nlll-_=838
    # ['>> .\\', 'nll', '-', '_', '=', '838']
    res: list[str] = list[str]()
    tmp: bool = False
    for ip in range(len(operand)):
        op = operand[ip]
        # if same state with prev in list
        # (only not for first element)
        if is_symbol_space(op) == tmp and ip > 0:
            res[-1] += op
        # if not same
        else:
            tmp = is_symbol_space(op)
            res.append(str())
            res[-1] = op
    return res


class Command:
    pass

class Plus(Command):
    operand: int
    def __init__(_operand: int):
        operand = _operand

class Minus(Command):
    operand: int
    def __init__(_operand: int):
        operand = _operand

class Next(Command):
    pass

class Prev(Command):
    pass

class Print(Command):
    pass

class Ins(Command):
    operand: int
    def __init__(_operand: int):
        operand = _operand

class Null(Command):
    pass

Program: type = list[Command]

def interpret_program(x: Program):
    print(f'------ interpreting... ------')
    stack: list[int] = [0]
    stack_ptr: int = 0
    for ip in range(len(x)):
        op = x[ip]
        if   isinstance(op, Plus):
            assert False, '`Plus` op is not implemented yet'
        elif isinstance(op, Minus):
            assert False, '`Minus` op is not implemented yet'
        elif isinstance(op, Next):
            print(f'----next {stack_ptr}----')
            stack_ptr += 1
            if stack_ptr > len(stack):
                stack.append(0)
        elif isinstance(op, Prev):
            print(f'----prev {stack_ptr}----')
            stack_ptr -= 1
        elif isinstance(op, Print):
            print(f'----print {stack_ptr}{stack}----')
            print( stack[stack_ptr] )
        else:
            assert False, f'interpret_program: unreachable_op: {op}'

class ParsingCommand(Enum):
    PLUS = auto(),
    MINUS = auto(),
    PRINT = auto(),
    NEXT = auto(),
    PREV = auto(),
    INS = auto(),
    CALL = auto(),
    NULL = auto(),

def main():
    lines: list[str] = []
    #read lines
    while True:
        lines.append(input())
        if lines[-1] == 'x':
            lines.pop()
            break
    print(f'--------------------')

    #join lines
    lines_str: str = ' __NEW_LINE__ '.join(lines)
    print(f'lines_str={repr(lines_str)} splitted={my_split(lines_str)}')

    #parsing
    splinp: str = for_every_el(my_split(lines_str), lambda x: x.strip())
    print(f'------ parsing... {len(splinp)} symbols ------')
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
                    case '>':
                        program.append(Next())
                    case '<':
                        program.append(Prev())
                    case '.':
                        program.append(Print())
                    case 'ea':
                        print('f')
                    case '__NEW_LINE__':
                        line_num += 1
                        print(f'   New line! ip={ip} {line_num}')
                    case '':
                        pass
                    case ' ':
                        pass
                    case _:
                        print(f'parsing (line {line_num}): unreachable command: op={repr(op)} ip={ip}', file=sys.stderr)
                        exit(1)
            case ParsingCommand.PLUS:
                command = Null()
                program.append(Plus(int(op)))
            case ParsingCommand.MINUS:
                command = Null()
                program.append(Minus(int(op)))
            case _:
                assert False, f'parsing (line {line_num}): unknown `command`: {command}'
    print(f'program={program}')
    interpret_program(program)

def test():
    pass

if __name__ == '__main__':
    main()
