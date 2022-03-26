#ifndef TOKENPIPEPARSER_H
#define TOKENPIPEPARSER_H

#include "SLT/ReaderAndPipe.h"
#include "SLT/Tree/TreeNode.h"


namespace slt{
    class TokenPipeParser : public DataPipe<TreeNode<std::string>>
    {
        public:
    };
}

#endif // TOKENPIPEPARSER_H
