//
// Created by Maxwell Morgan on 9/5/26.
//

#ifndef PHONK_STATEMENT_HPP
#define PHONK_STATEMENT_HPP

#include <memory>
#include <variant>
#include <vector>

#include <phonk/ast/expression.hpp>
#include <phonk/source/source_range.hpp>

namespace phonk::ast {

struct Stmt;

using StmtPtr = std::unique_ptr<Stmt>;

struct ExprStmt {
    ExprPtr expression;
};

struct BlockStmt {
    std::vector<StmtPtr> statements;
};

struct ReturnStmt {
    ExprPtr value;
};

using StmtNode = std::variant<
    ExprStmt,
    BlockStmt,
    ReturnStmt>;

struct Stmt {
    source::SourceRange range;
    StmtNode node;
};

}

#endif // PHONK_STATEMENT_HPP