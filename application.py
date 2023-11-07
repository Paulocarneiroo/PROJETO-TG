import sqlite3

def create_table():
    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS disciplinas (
            id INTEGER PRIMARY KEY,
            nome TEXT,
            nota1 REAL,
            nota2 REAL
        )
    ''')
    conn.commit()
    conn.close()

def register_subject():
    nome = input("Nome da disciplina: ")
    nota1 = float(input("Nota da 1ª unidade: "))
    nota2 = float(input("Nota da 2ª unidade:"))

    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('INSERT INTO disciplinas (nome, nota1, nota2) VALUES (?, ?, ?)', (nome, nota1, nota2))
    conn.commit()
    conn.close()

def calc_avg_status(nota1, nota2):
    avg = (nota1 + nota2) / 2
    if avg >= 6:
        return avg, "Aprovado"
    elif avg >= 4:
        return avg, "Precisando de Final"
    else:
        return avg, "Reprovado"

def list_situation():
    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('SELECT id, nome, nota1, nota2 FROM disciplinas')
    subjects = cursor.fetchall()
    conn.close()

    for subject in subjects:
        id, nome, nota1, nota2 = subject
        media, status = calc_avg_status(nota1, nota2)
        print(f"ID: {id}, Nome: {nome}, Nota 1: {nota1}, Nota 2: {nota2}, Média: {media}, Status: {status}")

def update_subject():
    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('SELECT id, nome, nota1, nota2 FROM disciplinas')
    disciplinas = cursor.fetchall()
    conn.close()

    for disciplina in disciplinas:
        id, nome, nota1, nota2 = disciplina
        print(f"ID: {id}, Nome: {nome}, Nota 1: {nota1}, Nota 2: {nota2}")

    id_atualizar = int(input("Digite o ID da disciplina que deseja atualizar: "))
    nome = input("Nome da disciplina: ")
    nota1 = float(input("Nota da 1ª unidade: "))
    nota2 = float(input("Nota da 2ª unidade:"))

    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('UPDATE disciplinas SET nome=?, nota1=?, nota2=? WHERE id=?', (nome, nota1, nota2, id_atualizar))
    conn.commit()
    conn.close()

def remove_subject():
    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('SELECT id, nome, nota1, nota2 FROM disciplinas')
    subjects = cursor.fetchall()
    conn.close()

    for subject in subjects:
        id, nome, nota1, nota2 = subject
        print(f"ID: {id}, Nome: {nome}, Nota 1: {nota1}, Nota 2: {nota2}")

    id_remover = int(input("Digite o ID da disciplina que deseja remover: "))

    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('DELETE FROM disciplinas WHERE id=?', (id_remover,))
    conn.commit()
    conn.close()

def remove_all_data():
    conn = sqlite3.connect('notas.db')
    cursor = conn.cursor()
    cursor.execute('DELETE FROM disciplinas')
    conn.commit()
    conn.close()

def main():
    create_table()

    while True:
        print("\nEscolha uma opção:")
        print("1 - Cadastrar nova disciplina")
        print("2 - Listar situação nas disciplinas")
        print("3 - Atualizar disciplina")
        print("4 - Remover disciplina específica")
        print("5 - Remover todos os dados")
        print("6 - Sair")

        escolha = input("Opção: ")

        if escolha == '1':
            register_subject()
        elif escolha == '2':
            list_situation()
        elif escolha == '3':
            update_subject()
        elif escolha == '4':
            remove_subject()
        elif escolha == '5':
            remove_all_data()
        elif escolha == '6':
            break
        else:
            print("Opção inválida. Tente novamente.")

if __name__ == "__main__":
    main()

