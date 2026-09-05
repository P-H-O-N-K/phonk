//
// Created by Maxwell Morgan on 9/5/26.
//

#ifndef PHONK_EXPRESSION_HPP
#define PHONK_EXPRESSION_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <variant>

#include <phonk/lexer/token.hpp>
#include <phonk/source/source_range.hpp>

namespace phonk::ast {

struct Expr;

// Expressions can contain other expressions
using ExprPtr = std::unique_ptr<Expr>;

using LiteralValue = std::variant<
    std::int64_t,
    double,
    std::string,
    bool>;

struct LiteralExpr {
    LiteralValue value;
};

struct IdentifierExpr {
    lexer::Token name;
};

struct UnaryExpr {
    lexer::Token op;
    ExprPtr operand;
};

struct BinaryExpr {
    ExprPtr left;
    lexer::Token op;
    ExprPtr right;
};


// Eliminates need for many classes and inheritance
using ExprNode = std::variant<
    LiteralExpr,
    IdentifierExpr,
    UnaryExpr,
    BinaryExpr>;

struct Expr {
    source::SourceRange range;
    ExprNode node;
};

}

#endif // PHONK_EXPRESSION_HPP