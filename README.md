import java.util.ArrayList;
import java.util.List;

// --- ENUMS ---
enum StatusEntrega {
    PENDENTE, ATRIBUIDA, FINALIZADA
}

// --- CLASSES DE ENTIDADE ---
class Rota {
    private String origem;
    private String destino;
    private double distancia;
    private int tempoEstimado;

    public Rota(String origem, String destino, double distancia, int tempoEstimado) {
        this.origem = origem;
        this.destino = destino;
        this.distancia = distancia;
        this.tempoEstimado = tempoEstimado;
    }

    @Override
    public String toString() {
        return String.format("%s -> %s (%skm)", origem, destino, distancia);
    }
}

class Motorista {
    private String nome;
    private String cpf;
    private String cnh;
    private boolean vinculado;

    public Motorista(String nome, String cpf, String cnh) {
        this.nome = nome;
        this.cpf = cpf;
        this.cnh = cnh;
        this.vinculado = false;
    }

    public String getNome() { return nome; }
    public boolean isVinculado() { return vinculado; }
    public void setVinculado(boolean vinculado) { this.vinculado = vinculado; }
}

class Entrega {
    private int codigo;
    private String destinatario;
    private StatusEntrega status;
    private double peso;
    private Rota rota;
    private Veiculo veiculoResponsavel;

    public Entrega(int codigo, String destinatario, double peso, Rota rota) {
        this.codigo = codigo;
        this.destinatario = destinatario;
        this.peso = peso;
        this.rota = rota;
        this.status = StatusEntrega.PENDENTE;
    }

    public void setStatus(StatusEntrega status) { this.status = status; }
    public StatusEntrega getStatus() { return status; }
    public void setVeiculo(Veiculo v) { this.veiculoResponsavel = v; }
    public int getCodigo() { return codigo; }

    @Override
    public String toString() {
        String vInfo = (veiculoResponsavel != null) ? veiculoResponsavel.getPlaca() : "Nenhum";
        return String.format("ID: %d | Status: %s | Destinatário: %s | Veículo: %s | Rota: %s", 
                codigo, status, destinatario, vInfo, rota);
    }
}

class Veiculo {
    private String placa;
    private String modelo;
    private Motorista motorista;
    private List<Entrega> entregasAtivas;
    private int totalFinalizadas;

    public Veiculo(String placa, String modelo) {
        this.placa = placa;
        this.modelo = modelo;
        this.entregasAtivas = new ArrayList<>();
        this.totalFinalizadas = 0;
    }

    public String getPlaca() { return placa; }

    public void associarMotorista(Motorista m) {
        if (!m.isVinculado()) {
            this.motorista = m;
            m.setVinculado(true);
        }
    }

    public void atribuirEntrega(Entrega e) {
        if (e.getStatus() == StatusEntrega.PENDENTE) {
            e.setStatus(StatusEntrega.ATRIBUIDA);
            e.setVeiculo(this);
            entregasAtivas.add(e);
        }
    }

    public void finalizarEntrega(int codigo) {
        for (Entrega e : entregasAtivas) {
            if (e.getCodigo() == codigo) {
                e.setStatus(StatusEntrega.FINALIZADA);
                entregasAtivas.remove(e);
                totalFinalizadas++;
                break;
            }
        }
    }

    public void exibirEntregas() {
        System.out.println("Entregas do Veículo " + placa + ":");
        entregasAtivas.forEach(System.out::println);
        System.out.println("Total pendentes/atribuídas: " + entregasAtivas.size());
    }

    public int getTotalFinalizadas() { return totalFinalizadas; }
}

// --- MAIN ---
public class SistemaLogistica {
    public static void main(String[] args) {
        // Inicialização obrigatória
        Motorista[] motoristas = {
            new Motorista("João", "111", "D"),
            new Motorista("Maria", "222", "E"),
            new Motorista("Carlos", "333", "B")
        };

        Veiculo[] veiculos = {
            new Veiculo("ABC-1234", "Volvo FH"),
            new Veiculo("XYZ-5678", "Scania R450"),
            new Veiculo("KJG-9900", "Mercedes Actros")
        };

        // Exemplo de uso das funcionalidades
        veiculos[0].associarMotorista(motoristas[0]);
        
        Rota r1 = new Rota("Belo Horizonte", "São Paulo", 580, 8);
        Entrega e1 = new Entrega(101, "Empresa A", 500.0, r1);
        Entrega e2 = new Entrega(102, "Empresa B", 250.0, r1);

        veiculos[0].atribuirEntrega(e1);
        veiculos[0].atribuirEntrega(e2);

        // Funcionalidade 3
        veiculos[0].exibirEntregas();

        // Funcionalidade 4
        veiculos[0].finalizarEntrega(101);
        System.out.println("Finalizadas pelo veículo " + veiculos[0].getPlaca() + ": " + veiculos[0].getTotalFinalizadas());
    }
}
