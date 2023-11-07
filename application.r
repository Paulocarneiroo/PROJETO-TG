corrida_data <- data.frame(
  Nome = c("Kleiton Silva", "Maria Santos", "Pedro Pereira", "Ana Oliveira", "Carlos Rodrigues"),
  TempoDeCorrida = c(34.56, 36.12, 38.20, 39.45, 40.18),
  PosicaoDeChegada = c(1, 2, 3, 4, 5)
)
hist(corrida_data$TempoDeCorrida, col = "blue", xlab = "Tempo (minutos)", ylab = "Frequência",
     main = "Histograma do Tempo de Corrida")
text(0, 60, labels = paste("Piloto:", corrida_data$Nome), adj = c(0, 1))

boxplot(corrida_data$TempoDeCorrida, col = "green", horizontal = TRUE, main = "Boxplot do Tempo de Corrida",
        xlab = "Tempo (minutos)")
text(10, 1, labels = paste("Piloto:", corrida_data$Nome), adj = c(1, 0))
