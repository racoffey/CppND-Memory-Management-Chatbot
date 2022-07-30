#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
#include <iostream>

using namespace std;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // The delete _chatBot command resulted in calling the deconstructor of the Chatbot a 2nd time leading 
    // to the initial segmentation fault when closing the Chatbot window.

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//Updated to support passing of Unique Pointer for edges
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}


//// STUDENT CODE
////

// Modifed to act on object and not pointer
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);

    _chatBot.SetCurrentNode(this);

}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{

    newNode->MoveChatbotHere(std::move(_chatBot));

}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // Modified to return raw pointer using "get"
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}