// external source

#pragma once

class Request
{
};

// ���������� NULL ���� ����� ��������� �������, ���� ��������� �� ������,
// ������� � ���������� ��������� �������
Request* GetRequest() throw();

// ������������ ������, �� ������ �� �������
void ProcessRequest(Request* request) throw();

extern const int NumberOfThreads;
