

/*
Em 1.sql, escreva uma consulta SQL para listar os títulos de todos os filmes lançados em 2008.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.

Em 2.sql, escreva uma consulta SQL para determinar o ano de nascimento de Emma Stone.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o ano de nascimento de Emma Stone.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Emma Stone.

Em 3.sql, escreva uma consulta SQL para listar os títulos de todos os filmes com data de lançamento igual ou posterior a 2018, em ordem alfabética.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Os filmes lançados em 2018 devem ser incluídos, assim como os filmes com datas de lançamento no futuro.

Em 4.sql, escreva uma consulta SQL para determinar o número de filmes com uma classificação IMDb de 10,0.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo o número de filmes com uma classificação de 10,0.

Em 5.sql, escreva uma consulta SQL para listar os títulos e anos de lançamento de todos os filmes de Harry Potter, em ordem cronológica.
Sua consulta deve gerar uma tabela com duas colunas, uma para o título de cada filme e outra para o ano de lançamento de cada filme.
Você pode presumir que o título de todos os filmes de Harry Potter começará com as palavras “Harry Potter” e que se o título de um filme começar com as palavras “Harry Potter”, é um filme de Harry Potter.

Em 6.sql, escreva uma consulta SQL para determinar a avaliação média de todos os filmes lançados em 2012.
Sua consulta deve gerar uma tabela com uma única coluna e uma única linha (sem incluir o cabeçalho) contendo a classificação média.

Em 7.sql, escreva uma consulta SQL para listar todos os filmes lançados em 2010 e suas classificações, em ordem decrescente por classificação. Para filmes com a mesma classificação, ordene-os em ordem alfabética por título.
Sua consulta deve gerar uma tabela com duas colunas, uma para o título de cada filme e outra para a classificação de cada filme.
Filmes sem classificação não devem ser incluídos no resultado.

Em 8.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram Toy Story.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Você pode presumir que há apenas um filme no banco de dados com o título Toy Story.

Em 9.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme lançado em 2004, ordenado por ano de nascimento.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Pessoas com o mesmo ano de nascimento podem ser listadas em qualquer ordem.
Não precisa se preocupar com pessoas que não têm ano de nascimento listado, desde que aqueles que têm ano de nascimento estejam listados em ordem.
Se uma pessoa apareceu em mais de um filme em 2004, ela só deve aparecer uma vez nos resultados.

Em 10.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que dirigiram um filme que recebeu uma classificação de pelo menos 9,0.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Se uma pessoa dirigiu mais de um filme que recebeu uma classificação de pelo menos 9,0, eles só devem aparecer em seus resultados uma vez.

Em 11.sql, escreva uma consulta SQL para listar os títulos dos cinco filmes com melhor classificação (em ordem) que Chadwick Boseman estrelou, começando com os de maior classificação.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Chadwick Boseman.

Em 12.sql, escreva uma consulta SQL para listar os títulos de todos os filmes em que Johnny Depp e Helena Bonham Carter estrelaram juntos.
Sua consulta deve gerar uma tabela com uma única coluna para o título de cada filme.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Johnny Depp.
Você pode presumir que há apenas uma pessoa no banco de dados com o nome Helena Bonham Carter.

Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.
Sua consulta deve gerar uma tabela com uma única coluna para o nome de cada pessoa.
Pode haver várias pessoas chamadas Kevin Bacon no banco de dados. Certifique-se de selecionar apenas Kevin Bacon nascido em 1958.
O próprio Kevin Bacon não deve ser incluído na lista resultante

cat filename.sql | sqlite3 movies.db run




*/
