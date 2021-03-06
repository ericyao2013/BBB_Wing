#ifndef ABSTRACT_NODE_H
#define ABSTRACT_NODE_H

#include <QObject>

namespace domain
{
    class AbstractNode: public QObject // TODO: Nodes to processes
    {
        Q_OBJECT

    public:
        AbstractNode(QObject* parent = nullptr);
        virtual ~AbstractNode();

    public slots:
        virtual void init();
        virtual void start() = 0;
        virtual void stop();

    private:
        Q_DISABLE_COPY(AbstractNode)
    };
}

#endif // ABSTRACT_NODE_H
