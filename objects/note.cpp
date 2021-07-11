#include "note.h"

Note::Note(int id, QObject *parent) : QObject(parent),
    id(id)
{

}

int Note::getId() const
{
    return id;
}

void Note::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

const QString &Note::getText() const
{
    return text;
}

void Note::setText(const QString &newText)
{
    if (text == newText)
        return;
    text = newText;
    emit textChanged();
}

