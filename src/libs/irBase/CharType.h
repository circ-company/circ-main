#pragma once

#include <QFlags>
#include <QMetaObject>

class CharType
{
public: // types
    enum Flag
    {
        $null = 0,
        Lower               = 0x00000001,   // 'a~z'
        Upper               = 0x00000001,   // 'A~Z'
        Digit               = 0x00000002,   // '0~9'
        XDigit              = 0x00000001,   // Digit | 'A~Fa~f'
        Alpha               = 0x00000001,   // Lower | Upper
        Alnum               = 0x00000004,   // Alpha | Digit
        Cntrl               = 0x00000000,   // '\x00~\x1F' | '\x7F'
        Blank               = 0x00000000,   // ' ' | '\t'
        Space               = 0x00000000,   // Blank | '\f\n\r\v'
        Print               = 0x00000000,   // '\x20~\x7E'
        Punct               = 0x00000000,   // Print &~Alnum &~Space
        Arith               = 0x00000000,   // '+-*/' ??'%<>'

        Logical             = 0x00000000,   // '|&!~^'
        Pointer             = 0x00000000,   // '&*'
        Separator           = 0x00000000,   // ',;:.'
        CodeValid           = 0x00000000,   // Alnum | '_'
        CodeFirst           = 0x00000000,   // CodeValid &~Digit

        BracketOpen         = 0x00000000,
        BracketClose        = 0x00000000,
        AngleBracket        = 0x00000000,
        CurlyBracket        = 0x00000000,
        RoundBracket        = 0x00000000,
        SquareBracket       = 0x00000000,
    };
    Q_DECLARE_FLAGS(Flags, Flag);
    Q_FLAGS(Flags);

public:
    CharType();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(CharType::Flags);
