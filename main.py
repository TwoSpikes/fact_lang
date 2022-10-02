from sys import stdin, stdout
from typing import TypeVar, Sequence
from enum import Enum, auto

DEBUG_MODE: bool = False

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
def my_in_in(a: list[T], b: T) -> bool:
    for ip in range(len(a)):
        op = a[ip]
        for ij in range(len(op)):
            oj = op[ij]
            if oj == b:
                return True
    return False

def first_enter(a: list, b) -> int:
    for ip in range(len(a)):
        op = a[ip]
        if op == b:
            return ip
    return -1

T: TypeVar = TypeVar('T')
def len_len(x: list[list[T]]) -> int:
    res: int = 0
    for ip in range(len(x)):
        op = x[ip]
        res += len(op)
    return res

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
    return my_in_in([
        str_range('a', 'z'),
        str_range('A', 'Z'),
        str_range('0', '9'),
        ['_',],
    ], x)


def my_split(operand: str) -> list[str]:
    res: list[str] = list[str]()
    prev: bool = False
    tmp: bool = False
    skip: int = 0
    for ip in range(len(operand)):
        if skip:
            skip -= 1
            continue
        op = operand[ip]
        match operand[ip]:
            case '%':
                match operand[ip + 1]:
                    case '#':
                        res.append(operand[ip: ip + 3])
                        skip = 3
                        continue
            case '#':
                tmp = False
                res.append(op)
                prev = is_symbol(op)
                continue
        if op in {' ', '\n'}:
            tmp = True
            continue
        # if space changed to symbol
        if tmp:
            tmp = False
            res.append(op)
            prev = is_symbol(op)
            continue
        # if stayed same (symbol)
        if is_symbol(op) == prev:
            if len(res): res[-1] += op
            else: res.append(op)
            continue
    # if symbol state changed
        prev = not prev
        res.append(op)
    return res

class BinaryCommand(Enum):
    PRINTL = auto(),
    ADD  = auto(),
    ADDL = auto(),
    SUB  = auto()
    SUBL = auto(),
    MOV  = auto(),
    NEW  = auto(),
Program: type = tuple[list[BinaryCommand], list]

def interpret_program(x: Program):
    print(f'[*] interpreting {len(x[0])} commands...')
    x[1].reverse()
    program_stack: list = list()
    stack_ptr: int = -1
    if not len(x):
        return
    for ip in range(len(x[0])):
        op = x[0][ip]
        match op:
            case BinaryCommand.ADD:
                assert False, '[#] `Plus` op is not implemented yet'
                continue
            case BinaryCommand.SUB:
                assert False, '[#] `Minus` op is not implemented yet'
                continue
            case BinaryCommand.PRINTL:
                index = x[1].pop()
                print(f'[$] PTINTL ({index})')
                print( program_stack[index] )
            case BinaryCommand.MOV:
                index = x[1].pop()
                operand = x[1].pop()
                print(f'[$] MOV (i{index})(o{operand})')
                program_stack[index] = operand
            case BinaryCommand.NEW:
                print(f'[$] NEW ({stack_ptr + 1})({program_stack})')
                program_stack.append(0)
            case _:
                assert False, f'[#] interpret_program: unreachable_op: {op}'

def parse_str_to_program(x: str) -> Program:
    print(f'[*] Parsing {len(x)} words...')

    class ParsingCommand(Enum):
        PLUS = auto(),
        MINUS = auto(),
        NEXT = auto(),
        PREV = auto(),
        PRINT = auto(),
        INS = auto(),
        NULL = auto(),
        NEWLINE = auto(),

    def parsing_warning(msg: str = 'Unknown', line_num: int = -1):
        print(f'[!] parsing (line {line_num}): WARNING: {msg}')

    def parsing_error(msg: str = 'Unknown', line_num: int = -1):
        global DEBUG_MODE
        print(f'[!] parsing (line {line_num}): ERROR: {msg}')
        if not DEBUG_MODE:
            exit(1)

    def parse_token_to_ParsingCommand(x: str, line_num: int = -1) -> ParsingCommand:
        match x:
            case '+': return ParsingCommand.PLUS
            case '-': return ParsingCommand.MINUS
            case 'next': return ParsingCommand.NEXT
            case 'prev': return ParsingCommand.PREV
            case 'print': return ParsingCommand.PRINT
            case 'ins': return ParsingCommand.INS
            case '%#l': return ParsingCommand.NEWLINE
            case '%#X': return ParsingCommand.NULL
            case '':
                parsing_error('Mysplit splitted operations and left extra empty string', line_num)
            case ' ':
                parsing_error('Mysplit splitted operations and left extra space string', line_num)
            case _:
                parsing_error(f'Unknown command: {repr(x)}', line_num)
                return ParsingCommand.NULL

    comment: bool = False

    program: list[ParsingCommand] = list[ParsingCommand]()
    line_num: int = 1

    res: Program = ([], [])
    skip: int = 0
    addr: int = -1
    for ip in range(len(x)):
        if skip:
            skip -= 1
            continue

        op = x[ip]
        if comment:
            if op == '%#l':
                comment = False
            continue
        else:
            if op == '#':
                comment = True
                continue
        if len(program):
            match program[0]:
                case ParsingCommand.NULL: pass
                case ParsingCommand.NEWLINE: line_num += 1
                case ParsingCommand.PLUS: return NotImplemented
                case ParsingCommand.MINUS: return NotImplemented
                case ParsingCommand.INS: return NotImplemented
                case ParsingCommand.NEXT: return NotImplemented
                case ParsingCommand.PRINT:
                    if op.isdigit():
                        res[0].append(BinaryCommand.NEW)

                        res[0].append(BinaryCommand.MOV)
                        addr += 1
                        res[1].append(addr)
                        res[1].append(int(op))

                        res[0].append(BinaryCommand.PRINTL)
                        res[1].append(addr)

                        skip = 1
                        continue
                    else: parsing_error(f'Print now is only for ints (This is {repr(op)} of type {type(op)})', line_num)
                case _: parsing_error(f'Unknown ParsingCommand: {op}', line_num)
        program.append(parse_token_to_ParsingCommand(op, line_num))
    return res

def parse_raw_input_to_str(x: list[str]) -> str:
    return my_split(' %#l '.join(x))

def main():
    VERSION_ARR: list[int] = [0, 0, 1]
    VERSION_POSTFIX: str = '-rc2'
    VERSION: str = '.'.join(for_every_el(VERSION_ARR, lambda x: str(x)))+VERSION_POSTFIX
    stdout.write(f'Welcome to !lang of version: {VERSION}\n')

    # read lines
    stdout.write('>>> ')
    stdout.flush()
    lines: list[str] = []
    try:
        for op in stdin:
            stdout.write('>>> ')
            stdout.flush()
            lines.append(f'{op}')
            if lines[-1] == 'FILEEND\n':
                lines.pop()
                break
    except:
        print()
        print(f'Keyboard interrupt!')
        exit(1)
    stdout.write('\n')

    if lines == []:
        print(f'No output!')
        return

    print(f'[*] Splitting {len(lines)} lines ({len_len(lines)} symbols)...')
    interpret_program(parse_str_to_program(parse_raw_input_to_str(lines)))

def test():
    pass

if __name__ == '__main__':
    main()
