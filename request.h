// external source

#pragma once

class Request
{
};

// возвращает NULL если нужно завершить процесс, либо указатель на память,
// которую в дальнейшем требуется удалить
Request* GetRequest() throw();

// обрабатывает запрос, но память не удаляет
void ProcessRequest(Request* request) throw();

extern const int NumberOfThreads;
