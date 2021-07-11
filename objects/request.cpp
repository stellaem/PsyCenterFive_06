#include "request.h"

Request::Request(QObject *parent) : QObject(parent)
{

}

int Request::getId() const
{
    return id;
}

void Request::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}

int Request::getIdClient() const
{
    return idClient;
}

void Request::setIdClient(int newIdClient)
{
    if (idClient == newIdClient)
        return;
    idClient = newIdClient;
    emit idClientChanged();
}

const QString &Request::getInternalCode() const
{
    return internalCode;
}

void Request::setInternalCode(const QString &newInternalCode)
{
    if (internalCode == newInternalCode)
        return;
    internalCode = newInternalCode;
    emit internalCodeChanged();
}

const QString &Request::getComplaint() const
{
    return complaint;
}

void Request::setComplaint(const QString &newComplaint)
{
    if (complaint == newComplaint)
        return;
    complaint = newComplaint;
    emit complaintChanged();
}

const QString &Request::getGoal() const
{
    return goal;
}

void Request::setGoal(const QString &newGoal)
{
    if (goal == newGoal)
        return;
    goal = newGoal;
    emit goalChanged();
}

const QString &Request::getNote() const
{
    return note;
}

void Request::setNote(const QString &newNote)
{
    if (note == newNote)
        return;
    note = newNote;
    emit noteChanged();
}

bool Request::getCompleted() const
{
    return completed;
}

void Request::setCompleted(bool newCompleted)
{
    if (completed == newCompleted)
        return;
    completed = newCompleted;
    emit completedChanged();
}

const QDate &Request::getStart() const
{
    return start;
}

void Request::setStart(const QDate &newStart)
{
    if (start == newStart)
        return;
    start = newStart;
    emit startChanged();
}

const QDate &Request::getEnd() const
{
    return end;
}

void Request::setEnd(const QDate &newEnd)
{
    if (end == newEnd)
        return;
    end = newEnd;
    emit endChanged();
}
